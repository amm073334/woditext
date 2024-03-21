/**
 * Convenience enums for calculating various flag values.
*/

#pragma once

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