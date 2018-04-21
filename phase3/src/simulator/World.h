#ifndef WORLD_H
#define WORLD_H

#include <string>
#include "Cell.h"
#include "Program.h"

class World{
private:
    static int log_num;
    int width;
    int length;
    Cell*** cells;
    Program** programs;
    Bug** red_bugs;
    Bug** black_bugs;
    
public:
    World(){};
    ~ World();
    void load(const std::string& world, const std::string& black_bug_file, const std::string& red_bug_file);
    void execute_cycle();
    
    Cell* get_cell(position_t& pos) const;
    position_t adjacent(const direction_t& dir, const position_t& pos) const;
    color_t other_color(const color_t& col) const;
    color_t* winner() const;
    
    /* stats */
    int red_food() const;
    int black_food() const;
    int red_count() const;
    int black_count() const;
    
    void error(const std::string& msg) const;
    void log(std::string& format) const;
};
#endif /* WORLD_H */