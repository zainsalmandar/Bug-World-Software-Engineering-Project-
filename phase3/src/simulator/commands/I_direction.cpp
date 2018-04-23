
#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_direction.h"

void I_direction::execute(Bug& b) {
    if(b.get_direction().val == this->d.val)
        b.set_state(this->x);
    else
        b.set_state(this->y);
}

void I_direction::parse(std::string& args){
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "direction")
        throw std::runtime_error("Wrong instruction called!");
    this->d.val = std::stoi (v[1],nullptr,10);
    this->x.val = std::stoi(v[2],nullptr,10);
    this->y.val = std::stoi (v[3],nullptr,10);
}
