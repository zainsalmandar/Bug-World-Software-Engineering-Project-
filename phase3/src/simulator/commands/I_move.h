/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_move.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 10:04 PM
 */

#ifndef I_MOVE_H
#define I_MOVE_H

#include "Instruction.h"

class I_move: public Instruction {
    private:
	state_t x;
	state_t y;
    public:
	void execute(Bug& b);
	void parse(std::string& args);
};

#endif /* I_MOVE_H */

