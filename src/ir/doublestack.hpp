#pragma once
#include <algorithm>

/**
 * Manages two stacks to handle variable assignment in a common event:
 * A "variable" stack grows toward higher indices, while a "temporary"
 * stack grows downward toward lower indices.
 * 
 * This _could_ be replaced with a single stack, but using two allows
 * regular variables and temporaries to be put on opposite ends of the
 * Cself space, improving readability in the output common file.
*/
class DoubleStack {
private:
    int var_stackpos;
    int temp_stackpos;
    
    int highest_var_stackpos;
    int lowest_temp_stackpos;

    int saved_var_stackpos;
    int saved_temp_stackpos;
public:
    DoubleStack() = delete;
    DoubleStack(int var_start, int temp_start)
        : var_stackpos(var_start)
        , temp_stackpos(temp_start)
        , highest_var_stackpos(var_start)
        , lowest_temp_stackpos(temp_start)
        , saved_var_stackpos(var_start)
        , saved_temp_stackpos(temp_start)
    {}
    
    int newvar() {
        if (highest_var_stackpos >= lowest_temp_stackpos) {
            std::cout << "exceeded maximum number of variables" << std::endl;
            exit(1);
        }
        int retval = var_stackpos++;
        highest_var_stackpos = std::max(var_stackpos, highest_var_stackpos);
        return retval;
    }
    
    int newtemp() {
        if (highest_var_stackpos >= lowest_temp_stackpos) {
            std::cout << "exceeded maximum number of temporary variables" << std::endl;
            exit(1);
        }
        int retval = temp_stackpos--;
        lowest_temp_stackpos = std::min(temp_stackpos, lowest_temp_stackpos);
        return retval;
    }

    void save_temp() { saved_temp_stackpos = temp_stackpos; }
    void restore_temp() { temp_stackpos = saved_temp_stackpos; }
};