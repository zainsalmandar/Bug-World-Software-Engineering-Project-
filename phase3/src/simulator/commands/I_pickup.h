/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_pickup.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 9:46 PM
 */

#ifndef I_PICKUP_H
#define I_PICKUP_H

#include "Instruction.h"

class I_pickup: public Instruction {

    private:
	state_t x;
	state_t y;
		
    public:
	void execute(Bug& b);
  	void parse(std::string& args);
};

#endif /* I_PICKUP_H */

