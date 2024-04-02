#pragma once

#include <vector>
#include <string>
#include <variant>

/**
* Wrapper for an int32_t to distinguish between normal integers and yobidasi hensuu.
*/
class WodNumber {
public:
    WodNumber(int32_t value) : value(value), is_ref(false) {}
    WodNumber(int32_t value, bool is_ref) : value(value), is_ref(is_ref) {}
    bool should_suppress_yobidasi() const { return !is_ref && value >= YOBIDASI_THRESHOLD; }
    bool is_malformed() const { return is_ref && value <= YOBIDASI_THRESHOLD; }
    int32_t value;
    bool is_ref;

    // Where the engine begins to interpret integers as references.
    static const int32_t YOBIDASI_THRESHOLD = 1000000;
};

/**
 * A line of code is represented in the binary with
 * a list of integers and a list of strings, along with
 * an indent level. There is always at least one integer,
 * which is the command ID.
 * 
 * For convenience, this struct represents the command ID 
 * separately from the other integer fields.
 * 
 * If the indent level is malformed, the common will not load.
*/
class Line {
public:
    virtual int32_t get_command_id() { return -1; }
protected:
    std::vector<int32_t> int_fields;
    std::vector<std::string> str_fields;
    char indent_level = 0;
private:
    /**
     * Updates the int_fields and str_fields vectors in the base class to
     * reflect whatever internal representation of the line data is contained
     * in a subclass.
     *
     * Should be called before a line is actually emitted to file.
    */
    virtual void update_base_data() {}

    friend class CommonEvent;
};

class EmptyLine : public Line {
public:
    int32_t get_command_id() override { return 0; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

// aka 変数操作
class ArithLine : public Line {
public:
    int32_t get_command_id() override { return 121; }
    
    enum assign_type {
        assign_eq          = 0x000,
        assign_plus_eq     = 0x100,
        assign_minus_eq    = 0x200,
        assign_times_eq    = 0x300,
        assign_div_eq      = 0x400,
        assign_mod_eq      = 0x500,
        assign_low_bound   = 0x600,
        assign_high_bound  = 0x700,
        assign_abs         = 0x800,
        assign_atan        = 0xf900, // for whatever reason, atan seems to have an extra F
        assign_sin         = 0xa00,
        assign_cos         = 0xb00
    };

    enum arith_op {
        op_plus     = 0x0000,
        op_minus    = 0x1000,
        op_times    = 0x2000,
        op_div      = 0x3000,
        op_mod      = 0x4000,
        op_bitand   = 0x5000
    };

    enum misc_flags {
        af_limit       = 0x01, // limit to +-999999
        af_jissuu      = 0x02, // 実数計算
        af_yobanai1    = 0x04,
        af_yobanai2    = 0x08,
        af_xban_dst    = 0x10,
        af_xban1       = 0x20,
        af_xban2       = 0x40
    };

    ArithLine(WodNumber dest, WodNumber arg0, WodNumber arg1, int32_t flags)
        : dest(dest.value), arg0(arg0.value), arg1(arg1.value), flags(flags) {
        if (arg0.should_suppress_yobidasi()) this->flags |= af_yobanai1;
        if (arg1.should_suppress_yobidasi()) this->flags |= af_yobanai2;
    }

private:
    int32_t dest;
    int32_t arg0;
    int32_t arg1;
    int32_t flags;

    void update_base_data() override {
        int_fields = { dest, arg0, arg1, flags };
        str_fields = {};
    }
};

// aka イベント処理中断
class ReturnLine : public Line {
public:
    int32_t get_command_id() override { return 172; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

// aka 条件分岐（変数）
class IntIfHeadLine : public Line {
public:
    int32_t get_command_id() override { return 111; }

    enum comp_op {
        op_gt,
        op_gte,
        op_eq,
        op_lte,
        op_lt,
        op_neq,
        op_mitasu
    };

    IntIfHeadLine() {}
    IntIfHeadLine(WodNumber arg0, WodNumber arg1, comp_op op) {
        branches.push_back(Branch(arg0, arg1, op));
    }
    
    /**
    * Add branch to the if statement.
    * @param arg0, arg1, op     Values to compare and operation to compare with.
    * @return                   How many branches the if statement now has. -1 if failed to insert.
    */
    int add_branch(WodNumber arg0, WodNumber arg1, comp_op op) {
        if (branches.size() >= MAX_BRANCH_COUNT) return -1;
        branches.push_back(Branch(arg0, arg1, op));
        return branches.size();
    }

    /**
    * Set whether or not this if statement has an else branch.
    * @param set    True if it does, false if not.
    */
    void set_else_branch(bool set) {
        has_else_branch = set;
    }

private:
    static const int MAX_BRANCH_COUNT = 4;

    struct Branch {
        Branch(WodNumber arg0, WodNumber arg1, comp_op op) 
            : arg0(arg0.value), arg1(arg1.value), flags(op) {
            if (arg1.should_suppress_yobidasi()) this->flags |= FLAG_YOBANAI;
        }
        static const int32_t FLAG_YOBANAI = 0x10;
        int32_t arg0;
        int32_t arg1;
        int32_t flags;
    };
    
    std::vector<Branch> branches;
    bool has_else_branch = false;
    static const int32_t FLAG_HASELSE = 0x10;

    void update_base_data() override {
        int_fields = { 
            static_cast<int32_t>(branches.size())
            | (has_else_branch ? FLAG_HASELSE : 0x00)
        };
        for (int i = 0; i < branches.size(); i++) {
            Branch b = branches.at(i);
            int_fields.push_back(b.arg0);
            int_fields.push_back(b.arg1);
            int_fields.push_back(b.flags);
        }

        str_fields = {};
    }
};

class BranchLine : public Line {
public:
    int32_t get_command_id() override { return 401; }
    BranchLine(int32_t branch_number) : branch_number(branch_number) {}
private:
    int32_t branch_number = 1;
    void update_base_data() override {
        int_fields = { branch_number };
        str_fields = {};
    }
};

class ElseBranchLine : public Line {
public:
    int32_t get_command_id() override { return 420; }
private:
    int32_t mysterious_arg = 0;
    void update_base_data() override {
        int_fields = { mysterious_arg };
        str_fields = {};
    }
};

class EndBranchLine : public Line {
public:
    int32_t get_command_id() override { return 499; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

class LoopForeverHeadLine : public Line {
public:
    int32_t get_command_id() override { return 170; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

class LoopCountHeadLine : public Line {
public:
    int32_t get_command_id() override { return 179; }
    LoopCountHeadLine(int32_t loop_times) : loop_times(loop_times) {}
private:
    int32_t loop_times;
    void update_base_data() override {
        int_fields = { loop_times };
        str_fields = {};
    }
};

class LoopEndLine : public Line {
public:
    int32_t get_command_id() override { return 498; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

class BreakLine : public Line {
public:
    int32_t get_command_id() override { return 171; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

class ContinueLine : public Line {
public:
    int32_t get_command_id() override { return 176; }
private:
    void update_base_data() override {
        int_fields = {};
        str_fields = {};
    }
};

class CallByNameLine : public Line {
public:
    int32_t get_command_id() override { return 300; }
    CallByNameLine(std::string name, std::vector<int32_t> int_args, std::vector<int32_t> str_args)
        : common_name(name), int_args(int_args), str_args(str_args)
        , flags(int_args.size() | (str_args.size() << 4)) {}
    CallByNameLine(std::string name, std::vector<int32_t> int_args, std::vector<int32_t> str_args, int32_t return_store)
        : common_name(name), int_args(int_args), str_args(str_args), return_store(return_store)
        , flags(int_args.size() | (str_args.size() << 4) | FLAG_HASRETURN) {}
    // TODO: support string literals -- use variants?
    //

private:
    static const int32_t FLAG_HASRETURN = 0x1000000;
    static const int32_t MASK_HASSTRLIT = 0x001f000;

    // this field is a bit of a mystery:
    // it seems to always be 0 in this line type, and changing it manually doesn't seem to do anything
    int32_t common_id = 0;

    // flags format:
    // 0001 0000 0001 1111 0000 0101 0101
    //                               ^ num int args (max 5)
    //                          ^ num str args (max 5)
    //                   ^ bool: is first str arg a string literal?
    //                ...
    //              ^ bool: is 5th str arg a string literal?
    //    ^ bool: does call store return value?
    int32_t flags;
    std::vector<int32_t> int_args;
    std::vector<int32_t> str_args;
    std::string common_name;
    int32_t return_store = 0;

    void update_base_data() override {
        int_fields = { common_id, flags };

        // for string args, if a string literal is used instead of a variable reference, just insert 0 for its int field
        for (auto iter = int_args.begin(); iter != int_args.end(); iter++) {
            int_fields.push_back(*iter);
        }
        for (auto iter = str_args.begin(); iter != str_args.end(); iter++) {
            int_fields.push_back(*iter);
        }

        // if call stores the return value in a location, there needs to be one last int field for the variable ref
        if (flags & FLAG_HASRETURN) int_fields.push_back(return_store);

        str_fields = { common_name };

        // if any string literal box is checked, a string literal must be inserted for all args
        if (flags & MASK_HASSTRLIT) {
            for (int i = 0; i < str_args.size(); i++) str_fields.push_back("");
        }
    }
};

class DBLine : public Line {
public:
    int32_t get_command_id() override { return 250; }

    // Whether or not to treat the value in assign as a reference.
    static const int32_t FLAG_XBAN_YOBIDASI = 0x1;

    // Whether or not to assign a DB value into a variable--the default is to assign a variable value into the DB.
    static const int32_t FLAG_ASSIGN_TO_VAR = 0x1000;

    enum db_type {
        cdb = 0x000,
        sdb = 0x100,
        udb = 0x200
    };

    enum assign_type {
        assign_eq           = 0x00,
        assign_plus_eq      = 0x10,
        assign_minus_eq     = 0x20,
        assign_times_eq     = 0x30,
        assign_div_eq       = 0x40,
        assign_mod_eq       = 0x50,
        assign_low_bound    = 0x60,
        assign_high_bound   = 0x70
    };

    typedef std::variant<int32_t, std::string> num_or_str;
    DBLine(num_or_str type, num_or_str data, num_or_str value, int32_t flags, num_or_str assign) : flags(flags) {
        if (const std::string* p = std::get_if<std::string>(&type)) {
            this->flags |= FLAG_STRING_TYPE;
            type_str = *p;
        }
        else {
            type_num = std::get<int32_t>(type);
        }

        if (const std::string* p = std::get_if<std::string>(&data)) {
            this->flags |= FLAG_STRING_DATA;
            data_str = *p;
        }
        else {
            data_num = std::get<int32_t>(data);
        }

        if (const std::string* p = std::get_if<std::string>(&value)) {
            this->flags |= FLAG_STRING_VALUE;
            value_str = *p;
        }
        else {
            value_num = std::get<int32_t>(value);
        }

        if (const std::string* p = std::get_if<std::string>(&assign)) {
            this->flags |= FLAG_USE_STRINGLIT;
            assign_str = *p;
        }
        else {
            assign_num = std::get<int32_t>(assign);
        }
    }
    
private:
    static const int32_t FLAG_USE_STRINGLIT = 0x2;
    static const int32_t FLAG_STRING_TYPE  = 0x10000;
    static const int32_t FLAG_STRING_DATA  = 0x20000;
    static const int32_t FLAG_STRING_VALUE = 0x40000;

    int32_t type_num = 0;
    int32_t data_num = 0;
    int32_t value_num = 0;
    int32_t flags = 0;
    int32_t assign_num = 0;

    std::string type_str;
    std::string data_str;
    std::string value_str;
    std::string assign_str;

    void update_base_data() override {
        // in the case that a string literal is being assigned, there are only four int fields
        if (flags & FLAG_USE_STRINGLIT) {
            int_fields = { type_num, data_num, value_num, flags };
            str_fields = { assign_str, type_str, data_str, value_str };
        }
        else {
            int_fields = { type_num, data_num, value_num, flags, assign_num };
            str_fields = { "", type_str, data_str, value_str };
        }
    }
};