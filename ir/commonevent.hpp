#pragma once

#include <string>
#include <vector>
#include <array>
#include <utility>
#include "commonenums.hpp"
#include "line.hpp"

typedef std::vector<std::pair<std::string, int32_t>> EnumList;

class CommonEvent {    
public:
    CommonEvent();
    ~CommonEvent();

    /**
     * Append an arbitrary line of code to the end of the common. 
     * Automatically handles indent level, based on the entered command.
     * @param command_id    ID of the command.
     * @param ifields       Vector of integer fields, *not* including the ID.
     * @param sfields       Vector of string fields.
    */
    void append(int32_t command_id, std::vector<int32_t> ifields, std::vector<std::string> sfields);

    /**
     * Append a line to the end of the code.
     * Automatically handles indent level, based on the entered command.
     * @param l             Pointer to the line to append.
    */
    void append(Line* l);

    /**
     * Add new parameter of the specified type.
     * @param name  Name of the parameter.
     * @return      Index of the new parameter, from 0-9. -1 if the max number of params is reached.
    */
    int new_int_param(std::string name);
    int new_str_param(std::string name);

    /**
     * Emits the entire common event object to output.
     * @param fs    The filestream to write to.
    */
    void emit_common(std::ofstream *fs);

    /**
     * Length of the string array containing arg names.
    */
    static const int32_t MAX_NUM_PARAM_NAMES = 11;

    /**
     * Length of the byte array containing arg type flags.
    */
    static const int32_t MAX_NUM_PARAM_FLAGS = 10;

    /**
     * Length of the array of enums; one for each of the ten args.
    */
    static const int32_t MAX_NUM_ENUM_LISTS = 10;

    /**
     * Length of the array of integers containing default integer arg values.
    */
    static const int32_t MAX_NUM_DEFAULTABLE_PARAMS = 5;
    
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
     * Number of parameters.
    */
    char num_int_params = 0;
    char num_str_params = 0;

    std::array<std::string, MAX_NUM_PARAM_NAMES> param_names;
    std::array<arg_flag_type, MAX_NUM_PARAM_FLAGS> param_flags;
    std::array<EnumList, MAX_NUM_ENUM_LISTS> enums;
    std::array<int32_t, MAX_NUM_DEFAULTABLE_PARAMS> default_args;
    std::array<std::string, MAX_NUM_CSELF_NAMES> cself_names;
    
    /**
     * List of code lines.
    */
    std::vector<Line*> lines;

    /**
     * Name of the return value, and which CSelf to return, from 0-99.
     * A return ID of -1 indicates no return value.
    */
    std::string return_name = "";
    int32_t return_cself_id = -1;

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
     * Calculates the indent of a line if appended to the end of the code.
     * Updates the indent of the line passed in.
     * @param l         Pointer to the line to append.
     * @return          The result as a signed byte.
    */
    void update_indent(Line* l);


    /**
     * Code generation
    */

    std::ofstream* fs = NULL;

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
     * @param l Pointer to the line to emit.
    */
    void emit_line(Line* l);

    /**
     * Emits the footer of the common event to output.
    */
    void emit_footer();



};
