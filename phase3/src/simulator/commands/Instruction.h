/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Instruction.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 3:50 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "World.h"
#include "Bug.h"
 
class Instruction {
    protected:
        World w;
    public:
    	virtual ~Instruction() {}
        virtual void parse(std::string& args) = 0;
        virtual void execute(Bug& b) = 0;
 };

#endif /* INSTRUCTION_H */

