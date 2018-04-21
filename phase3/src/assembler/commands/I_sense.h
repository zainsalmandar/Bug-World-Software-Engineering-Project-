#ifndef I_SENSE_H_
#define I_SENSE_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"

class I_sense : public Instruction {
    private:
        std::string dir;
        std::string cond;
        std::string on_fail;
    public:
        // Constructor
        I_sense(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif