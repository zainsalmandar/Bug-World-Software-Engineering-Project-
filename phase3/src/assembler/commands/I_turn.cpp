#include <string>
#include <iostream>
#include <regex>

#include "I_turn.h"
#include "Labels.h"
#include "utility.h"
#include "../../properties.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_turn::I_turn(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_turn::parse(std::string args, int line) {
    // Regex to be matched
    std::regex turnReg("[\t]*turn (\\w+)[\t]*");
    // contains the matches
    std::smatch match;
    if (std::regex_search(args, match, turnReg)) {
        // regex matched
        int isValid = isLeftRight(match[1]);
        if (isValid == -1) {
            // argument supplied was not "left" or "right"
            Instruction::error("Line "+ std::to_string(line) +": \""+ match.str(1) +"\" not a valid direction");
            return -1;
        }
        lr = isValid;
    } else {
        // regex did not match
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_turn::read() {
    return "";
}