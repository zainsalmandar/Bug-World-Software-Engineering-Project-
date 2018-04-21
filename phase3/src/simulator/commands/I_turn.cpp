/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <exception>
#include <stdexcept>

#include "I_turn.h"
#include "Bug.h"


void I_turn::execute(Bug& b){
    //trun left or right and then go to z
    if(lr.val != 0 || lr.val != 1)
        throw std::runtime_error("leftright out of range");
    else if(lr.val == 0) {
        direction_t newdir;
        newdir.val = (b.get_direction().val + 5) % 6;
        b.set_direction(newdir);
    }
    else {
        direction_t newdir;
        newdir.val = (b.get_direction().val + 1) % 6;
        b.set_direction(newdir);
    }
    b.set_state(z);
}

void I_turn::parse(std::string& args){
    
}