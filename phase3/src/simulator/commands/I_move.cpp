/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_move.h"
#include "World.h"

void I_move::execute(Bug& b){
    
    position_t temp = w.adjacent(b.get_direction(),b.get_position());
    position_t bug_pos = b.get_position();
    Cell *c = w.get_cell(temp);
    Cell *current = this->w.get_cell(bug_pos);
    
    if (c->has_obstruction())
        b.set_state(y);
    else {
        c->set_occupant(&b);
        current->set_occupant(NULL);
        b.set_position(temp);
        b.set_state(x);
    }
}

void I_move::parse(std::string& args){
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "move")
        throw std::runtime_error("Wrong instruction called!");
    this->x.val = std::stoi(v[1],nullptr,10);
    this->y.val = std::stoi (v[2],nullptr,10);
}
