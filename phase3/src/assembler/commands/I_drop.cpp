#include <string>
#include <iostream>

#include "I_drop.h"
#include "Labels.h"
#include "Instruction.h"

/**
 * @brief Constructor
 * 
 * @param list list of labels of file
 */
I_drop::I_drop(Labels list) : Instruction(list) {}


int I_drop::parse(std::string args, int line) {
    // drop instruction does not take any extra arguments
    this->line = line;
    return line+1;
}

std::string I_drop::read() {
    return "";
}