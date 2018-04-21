/**
 * @brief contains utitlity functions needed for parsing of instructions
 * 
 * @file utility.h
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>

bool isSenseDir(std::string value);
bool isCondition(std::string value);
bool isElse(std::string value);
bool isInteger(std::string value);
int isLeftRight(std::string value);

#endif