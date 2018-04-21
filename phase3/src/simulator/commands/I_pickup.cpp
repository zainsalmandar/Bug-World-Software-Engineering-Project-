/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_pickup.h"
#include "Cell.h"

void I_pickup::execute(Bug& b){
     //Pick up food from the current cell  and go to state x;
    // if there is no food in the current cell go to state y
    position_t p = b.get_position();
    Cell *c = this->w.get_cell(p);
    if(c->get_food() == 0)
        b.set_state(y);
    else {
        c->set_food(c->get_food()-1);
        b.set_food(true);
        b.set_state(x);
    }
}

void I_pickup::parse(std::string& args){
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "pickup")
        throw std::runtime_error("Wrong instruction called!");
	this->x.val = std::stoi(v[1],nullptr,10);
    this->y.val = std::stoi (v[2],nullptr,10);
}
