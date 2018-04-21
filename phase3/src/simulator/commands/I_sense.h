/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_sense.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 8:59 PM
 */

#ifndef I_SENSE_H
#define I_SENSE_H

#include "ExposedTypes.h"
#include "Instruction.h"

class I_sense: public Instruction {
    private:
        sensedir_t dir;
        state_t x;
        state_t y;
        condition_t condition;
    public:
        void execute(Bug& b);
        void parse(std::string& args);
    
};

#endif /* I_SENSE_H */

