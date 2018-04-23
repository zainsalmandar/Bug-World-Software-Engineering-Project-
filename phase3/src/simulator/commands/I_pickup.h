
/*
 * File:   I_pickup.h
 * Author: mvitanov
 *
 */

#ifndef I_PICKUP_H
#define I_PICKUP_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_pickup: public Instruction {

    private:
	      state_t x;
	      state_t y;

    public:
        I_pickup() : Instruction() {x = NULL; y = NULL;}
        I_pickup(World &w) : Instruction(w) {x = NULL; y = NULL;}
	      void execute(Bug& b);
  	    void parse(std::string& args);
};

#endif /* I_PICKUP_H */
