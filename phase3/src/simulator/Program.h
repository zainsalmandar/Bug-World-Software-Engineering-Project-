#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>
#include "Bug.h"
//#include "commands/Instruction.h"

class Program{
private:
    int id;
    std::vector<std::string> lines;
    //std::vector<Instruction> instructions; 
public:
    Program(const std::string& filename, int progId);
    void step(Bug b);
};
#endif /* PROGRAM_H */

