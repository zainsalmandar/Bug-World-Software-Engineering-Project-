/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_drop.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 10:06 PM
 */

#ifndef I_DROP_H
#define I_DROP_H

#include "Instruction.h"

class I_drop : public Instruction {
    private:
	state_t z;
    public:
	void execute(Bug& b);
	void parse(std::string& args);
};

#endif /* I_DROP_H */

