/**
 * Enum values used directly in a common file.
*/

#pragma once

/**
 * Indicates when the common should run.
*/
enum exec_type : char {
    when_called,
    on_condition,
    on_parallel_condition,
    always
};

/**
 * If the common automatically runs on some condition,
 * this indicates what operation the common will use to check the condition.
*/
enum exec_comp_type : char {
    greater_than,
    greater_or_equal,
    equal,
    less_or_equal,
    less_than,
    not_equal,
    bitwise_and
};

/**
 * Indicates if an arg should be a dropdown in the form.
*/
enum arg_flag_type : char {
    none,
    db,
    enum_
};

/**
 * Indicates the color of the enum.
*/
enum color_type : int32_t {
    black,
    red,
    blue,
    green,
    purple,
    yellow,
    gray
};
