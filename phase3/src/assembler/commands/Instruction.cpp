#include <string>
#include <iostream>

#include "Instruction.h"
#include "Labels.h"


/**
 * @brief Constructor
 * 
 * @param list instance of labels 
 */
Instruction::Instruction(Labels list) {
    l_list = list;
}


/**
 * @brief prints out an error message
 * 
 * Is called from derived classes in case of a parsing or resolving error
 * @param msg the message to be output 
 */
void Instruction::error(std::string msg) {
    std::cout << "Parse Error: " << msg << std::endl;
}


/**
 * @brief parses an input string
 * 
 * has to be defined in the derived classes
 * 
 * @param args the string to be parsed
 * @param line the line number
 * @return int the next line number
 */
int Instruction::parse(std::string args, int line) {
    return 0;
}

/**
 * @brief exports the stored data to output format
 * 
 * has to be defined in the derived classes
 * 
 * @return std::string the processed output string
 */
std::string Instruction::read() {
    return "";
}
