#ifndef I_DEFAULT_H_
#define I_DEFAULT_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"


/**
 * @brief placeholder for labels and goto statements
 */
class I_default : public Instruction {
    public:
        // Constructor
        I_default(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif