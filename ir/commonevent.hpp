#pragma once

#include <string>
#include <vector>
#include <array>
#include <utility>
#include "commonenums.hpp"
#include "customenums.hpp"

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
};

typedef std::vector<std::pair<std::string, int32_t>> EnumList;

class CommonEvent {    
public:
    CommonEvent();

    /**
     * Append an arbitrary line of code to the end of the common. 
     * Automatically handles indent level, based on the entered command.
     * @param command_id    ID of the command.
     * @param ifields       Vector of integer fields, *not* including the ID.
     * @param sfields       Vector of string fields.
    */
    void append(int32_t command_id, std::vector<int32_t> ifields, std::vector<std::string> sfields);

    /**
     * Append an arithmetic operation to the end of the code.
     * @param dest          Yobidasi of the place to store the result.
     * @param arg0, arg1    Arguments to perform operation on.
     * @param assign        Assignment operator to use.
     * @param op            Binary operator to use.
    */
    void a_arith(int32_t dest, int32_t arg0, int32_t arg1, assign_type assign, arith_op op);

    /**
     * Emits the entire common event object to output.
     * @param fs    The filestream to write to.
    */
    void emit_common(std::ofstream *fs);

    /**
     * Length of the string array containing arg names.
    */
    static const int32_t MAX_NUM_ARG_NAMES = 11;

    /**
     * Length of the byte array containing arg type flags.
    */
    static const int32_t MAX_NUM_ARG_FLAGS = 10;

    /**
     * Length of the array of enums; one for each of the ten args.
    */
    static const int32_t MAX_NUM_ENUM_LISTS = 10;

    /**
     * Length of the array of integers containing default integer arg values.
    */
    static const int32_t MAX_NUM_DEFAULTABLE_ARGS = 5;
    
    /**
     * Length of the array of strings containing cself names.
    */    
    static const int32_t MAX_NUM_CSELF_NAMES = 100;
    
    /**
     * Index of the common in the common list.
    */
    int32_t id = 0;

    /**
     * Name of the common.
    */
    std::string name = "";

    /**
     * Color of the common.
    */
    color_type color = black;

    /**
     * Memo attached to the common.
    */
    std::string memo = "";
    
    /**
     * When to run the common.
    */
    exec_type exec = when_called;

    /**
     * If common can trigger automatically, specifies op,
     * variable to compare, and constant to compare.
     * If true, then common is triggered automatically.
    */
    exec_comp_type exec_op = greater_than;
    int32_t cond_yobidasi = 2000000;
    int32_t cond_comp_value = 0;

    /**
     * Number of args.
    */
    char num_int_args = 0;
    char num_str_args = 0;

    std::array<std::string, MAX_NUM_ARG_NAMES> arg_names;
    std::array<arg_flag_type, MAX_NUM_ARG_FLAGS> arg_flags;
    std::array<EnumList, MAX_NUM_ENUM_LISTS> enums;
    std::array<int32_t, MAX_NUM_DEFAULTABLE_ARGS> default_args;
    std::array<std::string, MAX_NUM_CSELF_NAMES> cself_names;
    
    /**
     * List of code lines.
    */
    std::vector<Line> lines;

    /**
     * Name of the return value, and which CSelf to return, from 0-99.
    */
    std::string return_name = "";
    int32_t return_cself_id = 0;

private:

    /**
     * Utility
    */

    /**
     * Checks if a command can affect the indent level.
     * @param command   Command ID.
     * @return          Boolean result.
    */
    bool modifies_its_indent(int32_t command);
    bool increases_next_indent(int32_t command);
    bool is_codeblock_head(int32_t command);



    /**
     * Code generation
    */

    std::ofstream* fs;

    /**
     * Writes to output, interpreting the input
     * value as bytes.
     * @param in The value to emit.
    */
    void emit(int32_t in);
    void emit(char in);
    void emit(std::string in);

    /**
     * Emits the header of the common event to output.
    */
    void emit_header();

    /**
     * Emits a code line to output, formatted as:
     * An 8-bit number of integer fields,
     * the array of 32-bit integer fields,
     * the 8-bit indent level of the line,
     * an 8-bit number of string fields,
     * the array of string fields,
     * and one byte of padding.
     * @param l The line to emit.
    */
    void emit_line(Line l);

    /**
     * Emits the footer of the common event to output.
    */
    void emit_footer();



};
