/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_drop.h"
#include "World.h"
#include "Bug.h"

void I_drop::execute(Bug& b){
     //drop food in curr pos and go to z
    position_t p = b.get_position();
    Cell *x = this->w.get_cell(p);
    x->set_food(x->get_food()+1);
    b.set_food(false);
    b.set_state(z);
}

void I_drop::parse(std::string& args){
	std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
	
	if(v[0] != "drop")
        throw std::runtime_error("Wrong instruction called!");
    
    this->z.val = std::stoi (v[1],nullptr,10);
    
}
