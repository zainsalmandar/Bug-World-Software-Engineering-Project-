
/*
 * File:   I_turn.h
 * Author: mvitanov
 *
 */

#ifndef I_TURN_H
#define I_TURN_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_turn: public Instruction {
    private:
        tleftright_t lr;
	      state_t z;
    public:
        I_turn() : Instruction() {lr = NULL; z = NULL;}
        I_turn(World &w) : Instruction(w) {lr = NULL; z = NULL;}
	      void execute(Bug& b);
	      void parse(std::string& args);
};

#endif /* I_TURN_H */
