#pragma once

#include <vector>
#include <string>

/**
 * A line of code is represented with a list of integers and
 * a list of strings, along with an indent level. There is
 * always at least one integer, which is the command ID.
 * 
 * If the indent level is malformed, the common will not load.
*/
struct Line {
    std::vector<int32_t> int_fields;
    std::vector<std::string> str_fields;
    char indent_level = 0;
    virtual void update_base_data() {};
};

struct ArithLine : public Line {
    static const int32_t command_id = 121;

    enum arith_flag {
        af_limit       = 0x01,
        af_jissuu      = 0x02,
        af_yobanai1    = 0x04,
        af_yobanai2    = 0x08,
        af_yob_store   = 0x10,
        af_yob_arg1    = 0x20,
        af_yob_arg2    = 0x40
    };

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
    
    int32_t dest = 0;
    int32_t arg0 = 0;
    int32_t arg1 = 0;
    assign_type assign = assign_eq;
    arith_op op = op_plus;


    ArithLine() {}
    ArithLine(int32_t dest, int32_t arg0, int32_t arg1, assign_type assign, arith_op op) 
        : dest(dest), arg0(arg0), arg1(arg1), assign(assign), op(op) {}
    
    void update_base_data() override { int_fields = {command_id, dest, arg0, arg1, assign | op}; }

};