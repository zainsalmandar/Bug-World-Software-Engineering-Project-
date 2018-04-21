#ifndef CELL_H
#define CELL_H

#include "Marker.h"
#include "Bug.h"

class Cell{
private:
    Bug* occupant;
    bool obstructed;
    int food;
    bool home_black_bug;
    bool home_red_bug;
public:
    Marker mark;
    Cell(char symb);
    Bug* get_occupant() const {return occupant;};
    int get_food() const {return food;};
    int has_obstruction() const{return obstructed;};
    
    void set_occupant(Bug* new_occupant);
    void set_food(const int& new_food);
    
    bool is_black_home_area() const{return home_black_bug;};
    bool is_red_home_area() const{return home_red_bug;};
};
#endif /* CELL_H */

