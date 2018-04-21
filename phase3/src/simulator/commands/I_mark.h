/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_mark.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 9:41 PM
 */

#ifndef I_MARK_H
#define I_MARK_H

#include "Instruction.h"

class I_mark: public Instruction {
    private:
        int m;
        state_t z;
    public:
        void execute(Bug& b);
        void parse(std::string& args);
};

#endif /* I_MARK_H */

