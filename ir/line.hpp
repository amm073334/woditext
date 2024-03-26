#pragma once

#include <vector>
#include <string>

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
private:
    // Where the engine begins to interpret integers as references.
    static const int32_t YOBIDASI_THRESHOLD = 1000000;
    bool is_ref;
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
        assign_mod_eq      = 0x500
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
        af_limit       = 0x01,
        af_jissuu      = 0x02,
        af_yobanai1    = 0x04,
        af_yobanai2    = 0x08,
        af_yob_store   = 0x10,
        af_yob_arg1    = 0x20,
        af_yob_arg2    = 0x40
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
    LoopCountHeadLine(WodNumber loop_times) : loop_times(loop_times.value) {}
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