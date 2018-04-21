#include <string>
#include <iostream>
#include <regex>

#include "I_mark.h"
#include "Labels.h"
#include "utility.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_mark::I_mark(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_mark::parse(std::string args, int line) {
    // regex to be matched
    std::regex markReg("[\t]*mark ([+-]?[1-9]\\d*|0)[\t]*");
    // contains the matches
    std::smatch match;

    if (std::regex_search(args, match, markReg)) {
        // regex was successfully matched
        int markValue = stoi(match.str(1));
        if (markValue < 0 || markValue > 5) {
            // in mark i the value of i has to be between 0 and 5
            Instruction::error("Line "+ std::to_string(line) +": invalid argument: \""+ match.str(1) +"\"");
            return -1;
        } else {
            // value of i is between 0 and 5 and therefore acceptable
            mark = markValue;
        }
    } else {
        // regex did not match and therefore must be to litle arguments
        Instruction::error("Line "+ std::to_string(line) +": not enough or invalid argument");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_mark::read() {
    return "";
}

