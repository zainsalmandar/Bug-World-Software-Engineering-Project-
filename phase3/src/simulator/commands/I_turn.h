/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_turn.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 10:01 PM
 */

#ifndef I_TURN_H
#define I_TURN_H

#include "Instruction.h"

class I_turn: public Instruction {
    private:
        tleftright_t lr;
	state_t z;
    public:
	void execute(Bug& b);
	void parse(std::string& args);
};

#endif /* I_TURN_H */

