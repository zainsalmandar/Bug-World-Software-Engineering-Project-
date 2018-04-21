#include <stdexcept>
#include "Bug.h"

Bug::Bug(color_t i_col, int i_progid, int i_resting){
    if(i_col.val < 0 || i_col.val > 1){
        throw std::runtime_error("Value not in range");
    }
    else{
        color.val = i_col.val;
        prog_id = i_progid;
        resting = 0;
        dead = false;
        food = false;
        remaining_rest = i_resting;
    }
}

Bug::Bug(const Bug& bug){
    color.val = bug.color.val;
    state.val = bug.state.val;
    prog_id = bug.prog_id;
    pos.x = bug.pos.x;
    pos.y = bug.pos.y;
    dir.val = bug.dir.val;
    resting = bug.resting;
    remaining_rest = bug.remaining_rest;
    food = bug.food;
    dead = bug.dead;
}

void Bug::start_resting(){
    int temp = remaining_rest;
    if(remaining_rest > 0 && resting < temp){
        remaining_rest--;
        resting++;
    }
}

void Bug::set_state(const state_t& new_state){
    if(new_state.val < 0 || new_state.val > 9999){
        throw std::runtime_error("Value not in range");
    }
    else{
        state.val = new_state.val;
    }
}

void Bug::set_direction(const direction_t& new_dir){
    if(new_dir.val < 0 || new_dir.val > 5){
        throw std::runtime_error("Value not in range");
    }
    else {
        dir.val = new_dir.val;
    }
}

void Bug::set_position(const position_t& new_pos){
    pos.x = new_pos.x;
    pos.y = new_pos.y;
}

void Bug::kill(){
    if(!dead){
      dead = true;   
    }
    else throw std::runtime_error("Bug already dead");
}



