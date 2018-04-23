/*
 * File:   I_flip.h
 * Author: mvitanov
 *
 */

#ifndef I_FLIP_H
#define I_FLIP_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_flip: public Instruction {
    private:
        int p;
        state_t x;
        state_t y;
        int seed;
    public:
        I_flip() : Instruction() {p = seed = 0; x = NULL; y = NULL;}
        I_flip(World &w) : Instruction(w) {p = seed = 0; x = NULL; y = NULL;}
        void execute(Bug& b);
        void parse(std::string& args);
        int randomint();
};

#endif /* I_FLIP_H */
