/*
 * I_sense Implementation
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_sense.h"
#include "World.h"

void I_sense::execute(Bug& b) {
    bool cond = false;
    position_t temp;
    Cell *c;
    if (dir.val < 0 || dir.val > 3)
        throw std::runtime_error("sensedir in the class is out of scope");
    if(dir.val == 0) // Here
        temp = b.get_position();
    else if (dir.val == 1) // Ahead
        temp = this->w.adjacent(b.get_direction(), b.get_position());
    else if (dir.val == 2) { // adj pos left
        direction_t newdir;
        newdir.val = (b.get_direction().val + 5) % 6;
        temp = this->w.adjacent(newdir, b.get_position());
    }
    else { // adj pos right
        direction_t newdir;
        newdir.val = (b.get_direction().val + 1) % 6;
        temp = this->w.adjacent(newdir, b.get_position()); 
    }
    c = this->w.get_cell(temp);
    
    if (condition.val < 0 || condition.val > 9)
        throw std::runtime_error("condition in the class is out of scope");
    
    if(condition.val == 0)
    {
        if (c->get_occupant() != NULL)
        {
            if(b.get_color().val == c->get_occupant()->get_color().val)
                cond = true;
        }
    }
    else if (condition.val == 1) {
        if (c->get_occupant() != NULL)
        {
            if(b.get_color().val != c->get_occupant()->get_color().val)
                cond = true;
        }
    }
    else if (condition.val == 2) {
        if (c->get_occupant() != NULL)
        {
            if((b.get_color().val == c->get_occupant()->get_color().val) 
                    && c->get_occupant()->has_food())
                cond = true;
        }
    }
    else if (condition.val == 3) {
        if (c->get_occupant() != NULL)
        {
            if((b.get_color().val != c->get_occupant()->get_color().val) 
                    && c->get_occupant()->has_food())
                cond = true;
        }
    }
    else if (condition.val == 4) {
        if (c->get_occupant() == NULL && c->get_food() != 0)
            cond = true;
    }
    else if (condition.val == 5) {
        if(c->has_obstruction())
            cond = true;
    }
    else if (condition.val == 6) {
        mark_t tempmark;
        for (int i = 0; i < 6; i++) {
            tempmark.val = i;
            if (c->mark.check_marker(tempmark, b.get_color()))
                cond = true;
        }
    }
    else if (condition.val == 7) {
        mark_t tempmark;
        color_t other_col;
        if(b.get_color().val == 0)
            other_col.val = 1;
        else
            other_col.val = 0;
        
        for (int i = 0; i < 6; i++) {
            tempmark.val = i;
            if (c->mark.check_marker(tempmark, other_col))
                cond = true;
        }
    }
    else if (condition.val == 8) {
        if(b.get_color().val == 0) {
            if(c->is_black_home_area())
                cond = true;
        }
        else if (b.get_color().val == 1) {
            if (c->is_red_home_area())
                cond = true;
        }
        else 
            throw std::runtime_error("color is out of scope");
    }
    else if (condition.val == 9) {
        if(b.get_color().val == 0) {
            if(c->is_red_home_area())
                cond = true;
        }
        else if (b.get_color().val == 1) {
            if (c->is_black_home_area())
                cond = true;
        }
        else 
            throw std::runtime_error("color is out of scope");
    }
    
    if(cond){
        //move to state x
        b.set_state(x);
    } else {
        //move to state y
        b.set_state(y);
    }
}

void I_sense::parse(std::string& args) {
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "sense")
        throw std::runtime_error("Wrong instruction called!");
	
	if(v[1] == "here")
		this->dir.val = 0;	
	else if(v[1] == "leftahead")
		this->dir.val = 1;
	else if(v[1] == "ahead")
		this->dir.val = 2;
	else if(v[1] == "rightahead")
		this->dir.val = 3;
		
	this->x.val = std::stoi(v[2],nullptr,10);
    this->y.val = std::stoi (v[3],nullptr,10);
		
	if (v[4] == "friend")
		this->condition.val = 0;
	else if (v[4] == "foe")
		this->condition.val = 1;
	else if (v[4] == "friendwithfood")
		this->condition.val = 2;
	else if (v[4] == "foewithfood")
		this->condition.val = 3;
	else if (v[4] == "food")
		this->condition.val = 4;
	else if (v[4] == "rock")
		this->condition.val = 5;
	else if (v[4] == "marker")
		this->condition.val = 6;
	else if (v[4] == "foemarker")
		this->condition.val = 7;
	else if (v[4] == "home")
		this->condition.val = 8;
	else if (v[4] == "foehome")
		this->condition.val = 9;
	
}
