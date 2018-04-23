
/*
 * File:   Instruction.h
 * Author: mvitanov
 *
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../World.h"
#include "../Bug.h"

class Instruction {
    protected:
        World w;
    public:
        Instruction() {this->w = NULL;}
        Instruction(World& newworld) {w = newworld;}
        void setWorld(World& newworld) {w = newworld;}
        World getWorld() {return w;}
        virtual void parse(std::string& args) = 0;
        virtual void execute(Bug& b) = 0;
 };

#endif /* INSTRUCTION_H */
