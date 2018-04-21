#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
#include <stdexcept>

#include "Program.h"
#include "commands/I_default.h"
#include "commands/I_sense.h"
#include "commands/I_mark.h"
#include "commands/I_unmark.h"
#include "commands/I_pickup.h"
#include "commands/I_drop.h"
#include "commands/I_turn.h"
#include "commands/I_move.h"
#include "commands/I_flip.h"
#include "commands/I_direction.h"


/**
 * @brief Reads the input file into memory
 * 
 * @param filename input file
 */
Program::Program(std::string filename) {
    line = 0;
    // open file with ifstream
    std::ifstream file(filename);
    std::string s;
    while (getline(file, s)) {
        lines.push_back(s);
    }
    listLabels = Labels();
}


/**
 * @brief Raises an error if any errors occur
 * 
 * @param msg the message that will be raised
 */
void Program::error(std::string msg) {
    throw std::invalid_argument(msg);
}


/**
 * @brief goes through each line of the stored input file
 *  and creates the proper descendant of Instruction
 * 
 */
void Program::process() {
    // loop through the lines
    for (std::string s : lines) {
        // remove whitespace before first string
        s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
        // get the first string of the line
        std::string firstWord = s.substr(0, s.find(" "));

        if (std::regex_match (firstWord, std::regex("([a-zA-Z]|_)[a-zA-Z_0-9]+:"))) {
             // Line is a label
            listLabels.add_label(s.substr(0, s.size() - 1), line);
            I_default ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "goto") {
            // Line is a goto statement
            std::regex gotoReg("[\t]*goto (\\w+)[\t]*");
            std::smatch match;
            // Check if there is "goto $label" or not enough argmuments
            if (std::regex_search(s, match, gotoReg)) {
                listLabels.add_goto(match[1], line);
                I_default ins(listLabels);
                ins.parse(s, line);
                instructions.push_back(ins);
            } else {
                Program::error("Line "+ std::to_string(line) + ": not enough arguments supplied!");
            }
        } else if (firstWord == "mark") {
            // is mark statement
            I_mark ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "unmark") {
            // is unmark statement
            I_unmark ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "sense") {
            // is sense statement
            I_sense ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "pickup") {
            // is pickup statement
            I_pickup ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "drop") {
            // is drop statements
            I_drop ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "turn") {
            // is turn statement
            I_turn ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "move") {
            // is move statement
            I_move ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "flip") {
            // is flip statement
            I_flip ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else if (firstWord == "direction") {
            // is direction statement
            I_direction ins(listLabels);
            ins.parse(s, line);
            instructions.push_back(ins);
        } else {
            if (firstWord.length() != 0) {
                // not empty line
                std::cout << "Line "+ std::to_string(line) +": unknown instruction!" << std::endl;
            }
        }
        line++;
    }
}

void Program::output() {

}