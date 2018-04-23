
/*
 * File:   I_sense.h
 * Author: mvitanov
 *
 */

#ifndef I_SENSE_H
#define I_SENSE_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_sense: public Instruction {
    private:
        sensedir_t dir;
        state_t x;
        state_t y;
        condition_t condition;
    public:
        I_sense() : Instruction() {dir = NULL; condition = NULL; x = NULL; y = NULL;}
        I_sense(World &w) : Instruction(w) {dir = NULL; condition = NULL; x = NULL; y = NULL;}
        void execute(Bug& b);
        void parse(std::string& args);

};

#endif /* I_SENSE_H */
