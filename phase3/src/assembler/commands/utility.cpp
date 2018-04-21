#include <string>

#include "utility.h"

/**
 * @brief checks whether string is a valid sense direction
 * 
 * @param value string to be checked
 * @return true if it is valid
 * @return false if it is not valid
 */
bool isSenseDir(std::string value) {
    if (value == "ahead" || value == "leftahead" || value == "rightahead" || value == "here") {
        return true;
    }
    return false;
}


/**
 * @brief checks whether string is a valid condition
 * 
 * @param value string to be checked
 * @return true if it is avlid
 * @return false if it is not valid
 */
bool isCondition(std::string value) {
    if (value == "friend" || value == "foe" || value == "friendwithfood" 
        || value == "foewithfood" || value == "food" || value == "rock"
        || value == "marker" || value == "foemarker" || value == "home"
        || value == "foehome"
        ) {
        return true;
    }
    return false;
}


/**
 * @brief checks whether string is valid else
 * 
 * @param value string to be checked
 * @return true if valid
 * @return false if not valid
 */
bool isElse(std::string value) {
    if (value == "else") {
        return true;
    }
    return false;
}


/**
 * @brief checks whether string is an integer
 * 
 * @param value string to be checked
 * @return true if valid
 * @return false if not valid
 */
bool isInteger(std::string value) {
    return value.find_first_not_of( "0123456789" ) == std::string::npos;
}


/**
 * @brief checks whether string is left or right
 * 
 * @param value string to be checked
 * @return int -1 if not valid, 0 for left and 1 for right
 */
int isLeftRight(std::string value) {
    if (value == "left") {
        return 0;
    }
    if (value == "right") {
        return 1;
    }
    return -1;
}