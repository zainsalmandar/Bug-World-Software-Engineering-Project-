#ifndef I_UNMARK_H_
#define I_UNMARK_H_

#include <string>

#include "Instruction.h"
#include "../../properties.h"

class I_unmark : public Instruction {
    private:
        tmark mark;
    public:
        // Constructor
        I_unmark(Labels list);
        
        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif