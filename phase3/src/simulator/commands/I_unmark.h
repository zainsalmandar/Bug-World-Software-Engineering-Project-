
/*
 * File:   I_unmark.h
 * Author: mvitanov
 *
 */

#ifndef I_UNMARK_H
#define I_UNMARK_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_unmark: public Instruction {
    private:
	      int m;
	      state_t z;
    public:
        I_unmark() : Instruction() {m = 0; z = NULL;}
        I_unmark(World &w) : Instruction(w) {m = 0; z = NULL;}
	      void execute(Bug& b);
	      void parse(std::string& args);
};

#endif /* I_UNMARK_H */
