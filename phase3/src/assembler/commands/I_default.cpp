#include <string>
#include <iostream>

#include "I_default.h"
#include "Labels.h"
#include "Instruction.h"

/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_default::I_default(Labels list) : Instruction(list) {}


/**
 * @brief parses the input
 * 
 * @param args 
 * @param line 
 * @return int 
 */
int I_default::parse(std::string args, int line) {
    this->line = line;
    return line;
}

std::string I_default::read() {
    // TODO implement 
    return "";
}