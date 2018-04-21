#include <string>
#include <iostream>
#include <regex>

#include "I_pickup.h"
#include "Labels.h"
#include "Instruction.h"
#include "utility.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_pickup::I_pickup(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_pickup::parse(std::string args, int line) {
    // Regex to be matched
    std::regex pickupReg("[\t]*pickup (\\w+) (\\w+)[\t]*");
    // contains the matches
    std::smatch match;
    if (std::regex_search(args, match, pickupReg)) {
        // regex matched
        if (!isElse(match[1])) {
            // wrong instruction argument
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\"");
            return -1;
        }
        on_fail = match[2];      
    } else {
        // regex did not match
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_pickup::read() {
    return "";
}