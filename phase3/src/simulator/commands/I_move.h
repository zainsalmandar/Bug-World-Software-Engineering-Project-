
/*
 * File:   I_move.h
 * Author: mvitanov
 *
 */

#ifndef I_MOVE_H
#define I_MOVE_H

#include "Instruction.h"
#include "../ExposedTypes.h"
#include "../World.h"
#include "../Bug.h"

class I_move: public Instruction {
  private:
	   state_t x;
	   state_t y;
  public:
     I_move() : Instruction() {x = NULL; y = NULL;}
     I_move(World &w) : Instruction(w) {x = NULL; y = NULL;}
	   void execute(Bug& b);
     void parse(std::string& args);
};

#endif /* I_MOVE_H */
