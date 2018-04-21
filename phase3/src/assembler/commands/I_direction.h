#ifndef I_DIRECTION_H_
#define I_DIRECTION_H_

#include <string>

#include "Instruction.h"
#include "../../properties.h"
#include "Labels.h"


class I_direction : public Instruction {
    private:
        tdirection dir;
        std::string on_fail;
    public:
        // Constructor
        I_direction(Labels list);

        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif