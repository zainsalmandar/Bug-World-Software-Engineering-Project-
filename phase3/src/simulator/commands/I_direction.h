/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_direction.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 9:54 PM
 */

#ifndef I_DIRECTION_H
#define I_DIRECTION_H

#include "Instruction.h"

class I_direction: public Instruction {
    private:
		direction_t d;
		state_t x;
		state_t y;
    public:
    	I_direction();
		void execute(Bug& b);
		void parse(std::string& args);
};

#endif /* I_DIRECTION_H */

