#ifndef I_MARK_H_
#define I_MARK_H_

#include <string>

#include "Instruction.h"
#include "../../properties.h"
#include "Labels.h"

class I_mark : public Instruction {
    private:
        tmark mark;
    public:
        // Constructor
        I_mark(Labels list);
        
        // Methods
        int parse(std::string args, int line);
        std::string read();
};

#endif