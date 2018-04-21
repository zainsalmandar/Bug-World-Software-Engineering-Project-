#include <string>
#include <iostream>
#include <regex>

#include "I_direction.h"
#include "Instruction.h"
#include "Labels.h"
#include "utility.h"


/**
 * @brief constructor
 * 
 * @param list list of labels
 */
I_direction::I_direction(Labels list) : Instruction(list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_direction::parse(std::string args, int line) {
    // create new regex for parsing the line
    std::regex directionReg("[\t]*direction ([+-]?[1-9]\\d*|0) (\\w+) (\\w+)[\t]*");
    // object to contain the regex matches
    std::smatch match;
    if (std::regex_search(args, match, directionReg)) {
        // line matched the regez
        int dVal = stoi(match[1]);
        if (dVal < 0 || dVal > 5) {
            // value is out of defined bounds
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\". Has to be bigger than 0 and smaller than 5!");
            return -1;
        }
        dir = dVal;
        if (!isElse(match[2])) {
            // wrong thenelse
            Instruction::error("Line "+ std::to_string(line) +": invalid argument \""+ match.str(1) +"\"");
            return -1;
        }
        on_fail = match[3];
    } else {
        // line did not match the regex and must therefore have too few arguments
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_direction::read() {
    // TODO implement
    return "";
}