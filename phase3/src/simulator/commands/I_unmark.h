/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_unmark.h
 * Author: mvitanov
 *
 * Created on March 21, 2018, 9:51 PM
 */

#ifndef I_UNMARK_H
#define I_UNMARK_H

#include "Instruction.h"

class I_unmark: public Instruction {
    private:
	int m;
	state_t z;
    public:
	void execute(Bug& b);
	void parse(std::string& args);
};

#endif /* I_UNMARK_H */

