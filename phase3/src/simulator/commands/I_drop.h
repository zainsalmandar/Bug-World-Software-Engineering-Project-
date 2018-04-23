
/*
 * File:   I_drop.h
 * Author: mvitanov
 *
 */

#ifndef I_DROP_H
#define I_DROP_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_drop : public Instruction {
    private:
	      state_t z;
    public:
        I_drop() : Instruction() {z = NULL;}
        I_drop(World &w) : Instruction(w) {z = NULL;}
	      void execute(Bug& b);
	      void parse(std::string& args);
};

#endif /* I_DROP_H */
