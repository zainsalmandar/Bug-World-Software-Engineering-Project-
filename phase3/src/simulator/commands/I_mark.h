
/*
 * File:   I_mark.h
 * Author: mvitanov
 *
 */

#ifndef I_MARK_H
#define I_MARK_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_mark: public Instruction {
    private:
        int m;
        state_t z;
    public:
        I_mark() : Instruction() {m = 0; z = NULL;}
        I_mark(World &w) : Instruction(w) {m = 0; z = NULL;}
        void execute(Bug& b);
        void parse(std::string& args);
};

#endif /* I_MARK_H */
