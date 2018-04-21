#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <string>
#include <iostream>
#include <list>
#include <fstream>

#include "commands/Instruction.h"
#include "commands/Labels.h"

class Program{
    private:
        // stores the current line
        int line;
        // stores the file in memory
        std::list<std::string> lines;
        // stores the created instruction instances
        std::list<Instruction> instructions; 
        // instance of labels
        Labels listLabels;
    public:
        // Constructor
        Program(std::string filename);

        // Methods
        void error(std::string msg);
        void process();
        void output();
};

#endif