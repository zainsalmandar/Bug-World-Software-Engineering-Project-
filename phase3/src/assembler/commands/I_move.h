#ifndef I_MOVE_H_
#define I_MOVE_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"

class I_move : public Instruction {
    private:
        std::string on_fail;
    public:
        // Constructor
        I_move(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif