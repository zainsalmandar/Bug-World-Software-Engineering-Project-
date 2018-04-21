/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_flip.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 9:32 PM
 */

#ifndef I_FLIP_H
#define I_FLIP_H

#include "Instruction.h"

class I_flip: public Instruction {
    private:
        int p;
        state_t x;
        state_t y;
        int seed;
    public:
        void execute(Bug& b);
        void parse(std::string& args);
        int randomint();
};

#endif /* I_FLIP_H */

