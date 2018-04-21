#include <stdexcept>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include "Cell.h"

bool is_valid(char c){
    char valid_chars[4] = {'#', '.', '-','+'};
    if(isdigit(c)){
        return true;
    }
    else{
        for(int i=0;i<4;i++){
            if( c == valid_chars[i]){
                return true;
            }
        }
    }
    return false;
}


Cell::Cell(char symb){
	occupant = NULL;
    if(!is_valid(symb)){
        throw std::runtime_error("Not a valid character");
    }
    switch(symb){
        case '#':
            obstructed = true;
            food = 0;
            home_black_bug = home_red_bug = false;
            break;
        
        case '.':
        	obstructed = false;
            food = 0;
            home_black_bug = home_red_bug = false;
            break;
            
        case '-':
            obstructed = false;
            food = 0;
            home_black_bug = true;
            home_red_bug = false;
            break;
            
        case '+':
            obstructed = false;
            food = 0;
            home_black_bug = false;
            home_red_bug = true;
            break;
        
        default:
            obstructed = false;
            sscanf(&symb,"%d", &food);
            home_black_bug = home_red_bug = false;
            break;
    }
}

void Cell::set_occupant(Bug* new_occupant){
    if(!obstructed){
        occupant = new_occupant;
    }
    else{
        throw std::runtime_error("Cell is obstructed");
    }
}

void Cell::set_food(const int& new_food){
    if(!obstructed){
        food = new_food;
    }
    else{
        throw std::runtime_error("Cell is obstructed");
    }
}
