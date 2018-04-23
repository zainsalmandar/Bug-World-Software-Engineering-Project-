
/*
 * File:   I_direction.h
 * Author: mvitanov
 *
 */

#ifndef I_DIRECTION_H
#define I_DIRECTION_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_direction: public Instruction {
    private:
	      direction_t d;
	      state_t x;
	      state_t y;
    public:
        I_direction() : Instruction() {d = NULL; x = NULL; y = NULL;}
        I_direction(World &w) : Instruction(w) {d = NULL; x = NULL; y = NULL;}
	    void execute(Bug& b);
        void parse(std::string& args);
};

#endif /* I_DIRECTION_H */
