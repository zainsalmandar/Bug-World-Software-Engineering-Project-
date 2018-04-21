#ifndef BUG_H
#define BUG_H

#include "ExposedTypes.h"

class Bug {
private:
    color_t color;
    state_t state;
    int prog_id;
    position_t pos;
    direction_t dir;
    int resting;
    int remaining_rest;
    bool food;
    bool dead;

public:
    Bug(){};
    Bug(color_t i_col, int i_progid, int i_resting);
    Bug(const Bug& bug);
    
    void start_resting();
    bool rested() const { return resting > 0;};
    
    int get_progid() const {return prog_id;};
    color_t get_color() const {return color;};
    state_t get_state() const {return state;};
    direction_t get_direction() const {return dir;};
    position_t get_position() const  {return pos;};
    bool has_food() const {return food;};
    bool is_dead() const {return dead;};
    
    void set_state(const state_t& new_state);
    void set_direction(const direction_t& new_dir);
    void set_position(const position_t& new_pos);
    void set_food(bool new_food) {food = new_food;};
    void kill();
};

#endif /* BUG_H */

