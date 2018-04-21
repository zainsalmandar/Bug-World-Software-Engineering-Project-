#include <string>
#include <iostream>
#include <regex>

#include "I_unmark.h"
#include "Labels.h"
#include "utility.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_unmark::I_unmark(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_unmark::parse(std::string args, int line) {
    // Regex to be matched
    std::regex unmarkReg("[\t]*unmark ([+-]?[1-9]\\d*|0)[\t]*");
    // contains the matches
    std::smatch match;

    if (std::regex_search(args, match, unmarkReg)) {
        // regex matched
        // since the regex only matches a integer we do not 
        // have to check whether it is actually an integer
        int markValue = stoi(match.str(1));
        if (markValue < 0 || markValue > 5) {
            // value supplied is out of the allowed bounds
            Instruction::error("Line "+ std::to_string(line) +": invalid argument: \""+ match.str(1) +"\"");
            return -1;
        } else {
            mark = markValue;
        }
    } else {
        // regex did not match and therefore not enough arguments
        Instruction::error("Line "+ std::to_string(line) +": not enough or invalid argument");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_unmark::read() {
    return "";
}

