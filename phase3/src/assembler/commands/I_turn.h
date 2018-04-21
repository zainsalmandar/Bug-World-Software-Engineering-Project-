#ifndef I_TURN_H_
#define I_TURN_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"
#include "../../properties.h"


class I_turn : public Instruction {
    private:
        tleftright lr;
    public:
        // Constructor
        I_turn(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif