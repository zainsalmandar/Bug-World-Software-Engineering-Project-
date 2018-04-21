#include <string>
#include <iostream>
#include <regex>

#include "I_sense.h"
#include "Labels.h"
#include "utility.h"


/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_sense::I_sense(Labels list) : Instruction (list) {}


/**
 * @brief extracts necessary information from the given string
 * 
 * @param args string to be parsed
 * @param line line number
 * @return int next line number
 */
int I_sense::parse(std::string args, int line) {
    // create new regex for parsing the line
    std::regex senseReg("[\t]*sense (\\w+) (\\w+)\\s?([+-]?[1-9]\\d*|0)? (\\w+) (\\w+)[\t]*");
    // object to contain the regex matches
    std::smatch match;

    if (std::regex_search(args, match, senseReg)) {
        if (!isSenseDir(match[1])) {
            // first argument is not a valid sense direction
            Instruction::error("Line "+ std::to_string(line) +": invalid argument: \""+ match.str(1) +"\"");
            return -1;
        }
        if (!isCondition(match[2])) {
            // second argument is not a valid condition
            Instruction::error("Line "+ std::to_string(line) +": invalid argument: \""+ match.str(2) +"\"");
            return -1;
        }
        dir = match[1];
        cond = match[2];
        if (match[2] == "marker" && isInteger(match[3])) {
            // if the condition is a marker the next match is
            // a integer value
            int temp = stoi(match[3]);
            if (temp < 0 || temp > 5) {
                // value of marker is out ouf bounds
                Instruction::error("Line "+ std::to_string(line) +": invalid argument: \""+ match.str(3) +"\"");
                return -1;
            }
            cond = cond + " " + match.str(3);
            if (isElse(match[4]) && match.size() > 4) {
                on_fail = match[5];
            } else {
                // no else statement supplied
                Instruction::error("Line "+ std::to_string(line) +": too few arguments");
                return -1;
            }
        } else if (isElse(match[4])) {
            on_fail = match[5];
        } else {
            Instruction::error("Line "+ std::to_string(line) +": too few arguments");
            return -1;
        }
    } else {
        // regex did not match and therefore not enough arguments supplied
        Instruction::error("Line "+ std::to_string(line) +": too few arguments");
        return -1;
    }
    this->line = line;
    return line+1;
}

std::string I_sense::read() {
    return "";
}