#pragma once

#include <vector>
#include <fstream>
#include "commonevent.hpp"

class CommonFile {
public:
    /**
     * Adds a common event to file.
     * @param cev   Unique pointer to the common event.
     * @return      Non-owning pointer to the event.
    */
    CommonEvent* add_common(std::unique_ptr<CommonEvent> cev);

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
    std::vector<std::unique_ptr<CommonEvent>> clist;

};