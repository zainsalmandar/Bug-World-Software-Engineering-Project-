#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>

#include "Labels.h"

class Instruction {
    protected:
        // instance of labels that has all labels and goto statements
        Labels l_list;
        // stores line that the instruction is from.
        int line;
    public:
        // Constructor
        Instruction(Labels list);

        // Methods
        void error(std::string msg);
        // virtual methods have to be defined in derived classes
        virtual std::string read();
        virtual int parse(std::string args, int line);
};

#endif