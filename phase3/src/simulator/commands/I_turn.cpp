
#include <exception>
#include <stdexcept>

#include "I_turn.h"


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
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "turn")
        throw std::runtime_error("Wrong instruction called!");
    this->lr.val = std::stoi (v[1],nullptr,10);
    this->z.val = std::stoi (v[2],nullptr,10);
}
