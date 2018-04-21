#ifndef I_FLIP_H_
#define I_FLIP_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"

class I_flip : public Instruction {
    private:
        int p;
        std::string on_fail;
    public:
        // Constructor
        I_flip(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif