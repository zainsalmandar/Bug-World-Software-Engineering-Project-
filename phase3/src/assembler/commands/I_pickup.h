#ifndef I_PICKUP_H_
#define I_PICKUP_H_

#include <string>

#include "Instruction.h"
#include "Labels.h"

class I_pickup : public Instruction {
    private:
        std::string on_fail;
    public:
        // Constructor
        I_pickup(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif