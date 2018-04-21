#include <string>
#include <iostream>
#include <regex>

#include "I_move.h"
#include "Instruction.h"
#include "Labels.h"
#include "utility.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_move::I_move(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_move::parse(std::string args, int line) {
    // regex to be matched
    std::regex moveReg("[\t]*move (\\w+) (\\w+)[\t]*");
    // contains the matched results
    std::smatch match;
    if (std::regex_search(args, match, moveReg)) {
        if (!isElse(match[1])) {
            // arguments was not "else"
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\"");
            return -1;
        }
        on_fail = match[2];      
    } else {
        // regex did not match and therefore not enough arguments
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_move::read() {
    return "";
}