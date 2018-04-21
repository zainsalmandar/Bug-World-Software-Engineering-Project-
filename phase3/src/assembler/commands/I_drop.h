#ifndef I_DROP_H_
#define I_DROP_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"

class I_drop : public Instruction {
    public:
        // Constructor
        I_drop(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif