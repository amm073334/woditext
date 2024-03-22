#include <iostream>
#include <fstream>
#include "commonevent.hpp"

CommonEvent::CommonEvent() {
    // fill arrays where uninitialization would cause weird values
    arg_flags.fill(none);
    default_args.fill(0);
}

CommonEvent::~CommonEvent() {
    // free code lines
    for (auto iter = lines.begin(); iter != lines.end(); iter++) {
        delete *iter;
    }
}

/**
 * IR modification
*/

bool CommonEvent::modifies_its_indent(int32_t command) {
    switch (command) {
        case 401: // conditional branch start
        case 420: // else branch start
        case 402: // sentakusi keypress branch
        case 421: // sentakusi cancel branch
        case 498: // loop end
        case 499: // conditional end
            return true;
        default:
            return false;
    }
}

bool CommonEvent::increases_next_indent(int32_t command) {
    switch (command) {
        case 401: // conditional branch start
        case 420: // else branch start
        case 402: // sentakusi keypress branch
        case 421: // sentakusi cancel branch
        case 170: // loop head
        case 179: // loop x times head
            return true;
        default:
            return false;
    }
}

bool CommonEvent::is_codeblock_head(int32_t command) {
    switch (command) {
        case 102: // sentakusi
        case 111: // integer conditional
        case 112: // string conditional
        case 170: // loop
        case 179: // loop x times
            return true;
        default:
            return false;
    }
}

void CommonEvent::update_indent(Line* l) {
    if (lines.empty()) {
        l->indent_level = 0;
    } else {
        int32_t command_id = l->int_fields.at(0);
        char prev_indent = lines.back()->indent_level;
        int32_t prev_command = lines.back()->int_fields.at(0);
        
        if (modifies_its_indent(command_id)) {
            if (modifies_its_indent(prev_command) || is_codeblock_head(prev_command)) {
                l->indent_level = prev_indent;
            } else {
                l->indent_level = prev_indent - 1;
            }
        } else {
            if (increases_next_indent(prev_command)) {
                l->indent_level = prev_indent + 1;
            } else {
                l->indent_level = prev_indent;
            }
        }    
    }
}

void CommonEvent::append(int32_t command_id, std::vector<int32_t> ifields, std::vector<std::string> sfields) {
    // handle fields
    Line* l = new Line;
    l->int_fields.push_back(command_id);
    for (size_t i = 0; i < ifields.size(); i++) {
        l->int_fields.push_back(ifields.at(i));
    }
    l->str_fields = sfields;
    
    // handle indent
    update_indent(l);
    
    lines.push_back(l);
}

void CommonEvent::append(Line* l) {
    update_indent(l);
    lines.push_back(l);
}


/**
 * Code generation
*/

void CommonEvent::emit(int32_t in) {
    fs->write((char*)(&in), sizeof(int32_t));
}

void CommonEvent::emit(char in) {
    fs->write((char*)(&in), sizeof(char));
}

void CommonEvent::emit(std::string in) {
    int32_t str_len = in.length();
    emit(str_len + 1);
    for (size_t i = 0; i < str_len; i++) {
        emit(in.at(i));
    }
    emit('\x00');
}

void CommonEvent::emit_line(Line* l) {
    // if line has some kind of unique data representation, ask it to update its base data members first
    l->update_base_data();

    char num_ifields = l->int_fields.size();
    emit(num_ifields);
    for (size_t i = 0; i < num_ifields; i++) {
        emit(l->int_fields.at(i));
    }

    emit(l->indent_level);

    char num_sfields = l->str_fields.size();
    emit(num_sfields);
    for (size_t i = 0; i < num_sfields; i++) {
        emit(l->str_fields.at(i));
    }

    emit('\x00');
}

void CommonEvent::emit_header() {
    // byte 8e
    emit('\x8e');

    // common event ID
    emit(id);

    // condition
    emit(exec);
    emit(cond_yobidasi);
    emit(cond_comp_value);

    // argcount
    emit(num_int_args);
    emit(num_str_args);

    // common event name
    emit(name);
    
    // linecount
    emit((int32_t)lines.size());
}

void CommonEvent::emit_footer() {
    // mystery string
    emit("");

    // memo
    emit(memo);

    // mystery byte 8f
    emit('\x8f');

    // arg names
    emit(MAX_NUM_ARG_NAMES);
    for (size_t i = 0; i < MAX_NUM_ARG_NAMES; i++) {
        emit(arg_names.at(i));
    }

    // arg flags
    emit(MAX_NUM_ARG_FLAGS);
    for (size_t i = 0; i < MAX_NUM_ARG_FLAGS; i++) {
        emit(arg_flags.at(i));
    }

    // argument enums: first write name strings, then write integer values
    emit(MAX_NUM_ENUM_LISTS);
    for (size_t i = 0; i < MAX_NUM_ENUM_LISTS; i++) {
        int32_t enum_len = enums.at(i).size();
        emit(enum_len);
        for (size_t j = 0; j < enum_len; j++) {
            emit(enums.at(i).at(j).first);
        }
    }
    emit(MAX_NUM_ENUM_LISTS);
    for (size_t i = 0; i < MAX_NUM_ENUM_LISTS; i++) {
        int32_t enum_len = enums.at(i).size();
        emit(enum_len);
        for (size_t j = 0; j < enum_len; j++) {
            emit(enums.at(i).at(j).second);
        }
    }

    // initial values for args in common form
    emit(MAX_NUM_DEFAULTABLE_ARGS);
    for (size_t i = 0; i < MAX_NUM_DEFAULTABLE_ARGS; i++) {
        emit(default_args.at(i));
    }

    // mystery byte 90
    emit('\x90');

    // name color
    emit(color);

    // cself names -- do not emit array length
    for (size_t i = 0; i < MAX_NUM_CSELF_NAMES; i++) {
        emit(cself_names.at(i));
    }

    // mystery byte 91
    emit('\x91');

    // mystery string
    emit("");

    // mystery byte 92
    emit('\x92');

    // name of return value
    emit(return_name);

    // id of cself to return
    emit(return_cself_id);
    
    // mystery byte 92
    emit('\x92');
}

void CommonEvent::emit_common(std::ofstream *fs) {
    this->fs = fs;
    
    // header
    emit_header();

    // code body
    int32_t linecount = lines.size();
    for (size_t i = 0; i < linecount; i++) {
        emit_line(lines.at(i));
    }

    // footer
    emit_footer();

    this->fs = NULL;
}