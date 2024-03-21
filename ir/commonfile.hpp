#pragma once

#include <vector>
#include <fstream>
#include "commonevent.hpp"

class CommonFile {
public:
    /**
     * Adds a common event to file.
     * @param cev A pointer to the common event.
    */
    void add_common(CommonEvent* cev);

    /**
     * Writes common event out to file.
    */
    void generate(const char *outfile);

private:
    /**
     * Four bytes located at the beginning of every .common file.
    */
    static const int32_t MAGIC_NUMBER = 0x030C386D;
    
    /**
     * List of common events in file.
    */
    std::vector<CommonEvent*> clist;

};