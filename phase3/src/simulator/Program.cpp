#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <stdexcept>

#include "Program.h"

Program::Program(const std::string& filename, int progId){
	id = progId;

	std::ifstream in(filename);
	std::string s;

	while(getline(in,s)){
		lines.push_back(s);
	}

	for (std::string s:lines) {
        s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
        // get the first string of th
        std::string firstWord = s.substr(0, s.find(" "));
        if (firstWord == "mark") {
            // is mark statement
            I_mark ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "unmark") {
            // is unmark statement
            I_unmark ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "sense") {
            // is sense statement
            I_sense ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "pickup") {
            // is pickup statement
            I_pickup ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "drop") {
            // is drop statements
            I_drop ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "turn") {
            // is turn statement
            I_turn ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "move") {
            // is move statement
            I_move ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "flip") {
            // is flip statement
            I_flip ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else if (firstWord == "direction") {
            // is direction statement
            I_direction ins();
            ins.parse(s);
            instructions.push_back(ins);
        } else {
            if (firstWord.length() != 0) {
                // not empt
                std::cout << "Line "+ std::to_string(line) +": unknown instruction!" << std::endl;
            }
        }
    }
    id++;
}

void Program::step(Bug b){
	if (!b.is_dead() && b.get_progid() == id){
		for(int i=0;i<instructions.size();i++){
			instructions[i].execute();
		}
		return;
	}
	return;
}