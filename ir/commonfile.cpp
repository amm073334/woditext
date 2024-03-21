#include <iostream>
#include <vector>
#include <fstream>
#include "commonfile.hpp"

void CommonFile::add_common(CommonEvent* cev) {
    clist.push_back(cev);
}

void CommonFile::generate(const char *outfile) {
    
    std::ofstream fs = std::ofstream(
        outfile, 
        std::ios::out 
        | std::ios::binary 
        | std::ios::trunc
    );

    // write magic field
    fs.write((char*)(&MAGIC_NUMBER), sizeof(MAGIC_NUMBER));

    // write common count
    int32_t num_commons = clist.size();
    fs.write((char*)(&num_commons), sizeof(num_commons));

    // write commons
    for (size_t i = 0; i < num_commons; i++) {
        clist.at(i)->emit_common(&fs);
    }

    fs.close();
    
}