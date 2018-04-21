#include <string>
#include <iostream>
#include <regex>

#include "I_flip.h"
#include "Labels.h"
#include "Instruction.h"
#include "utility.h"


/**
 * 
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_flip::I_flip(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_flip::parse(std::string args, int line) {
    // Regex to be matched
    std::regex flipReg("[\t]*flip ([+-]?[1-9]\\d*|0) (\\w+) (\\w+)[\t]*");
    // contains the matches
    std::smatch match;
    if (std::regex_search(args, match, flipReg)) {
        // Regex got succesfully matched
        int pVal = stoi(match[1]);
        if (pVal <= 0) {
            // value for p argument has to be at least 1
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\". Has to be bigger than 0!");
            return -1;
        }
        p = pVal;
        if (!isElse(match[2])) {
            // is not else
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\"");
            return -1;
        }
        on_fail = match[3];      
    } else {
        // regex did not match
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}


std::string I_flip::read() {
    return "";
}