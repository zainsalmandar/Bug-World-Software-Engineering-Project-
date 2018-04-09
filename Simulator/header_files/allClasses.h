/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


#ifndef ALLCLASSES_H
#define ALLCLASSES_H

struct tcolor{
    int tcolor;
};

struct tstate{
    int tcolor;
};

struct tdirection{
    int tcolor;
};


struct tposition{
    int tcolor;
};

struct tsensedir{
    int tsensedir;
};

struct tleftright{
    int tleftright;
};

struct tmark{
    int tmark;
};

struct tcondition{
    int tcondition;
};

struct tposition{
    int x;
    int y;
};

class Bug{
public:
    Bug(); //Default Constructor;
    Bug(tcolor i_col, int i_progid, int i_resting);
    void start_resting;
    bool rested();
    int get_progid();
    tcolor get_color();
    tstate get_state();
    tdirection get_direction();
    tposition get_position();
    bool get_food();
    bool is_dead();
    
    void start_resting();
    void set_state(tstate new_state);
    void set_direction(tdirection new_direction);
    void set_position(tposition new_position);
    void set_food(tdirection new_direction);
    
    void kill();
    
    
private:
    
    tcolor color;
    tstate state;
    int prog_id;
    tposition pos;
    tdirection direction;
    int resting;
    int remaining_rest;
    bool food;
    bool dead;
};


class World{

public:
    
    Cell get_cell(tposition pos);
    tposition adjacent(tdirection dir, tposition pos);
    tcolor other_color(tcolor col);
    tcolor winner();
    int red_food();
    int black_food();
    int red_count();
    int black_count();
    
    void load(string filename);
    void execute_cycle();
    void error(string msg);
    void log(string format);
    
private:

    int Width;
    int Length;
    
};

class Cell {
public:
    
    Cell(char symb);
    
    Bug get_occupant();
    int get_food();
    bool get_obstructed();
    bool is_black_home_area();
    bool is_red_home_area();
    
    void set_occupant();
    void set_food();
    
private:
    Bug occupant;
    bool obstructed;
    int food;
    Marker mark;
    bool home_black_bug;
    bool home_red_bug;
};


class Instruction{

public:
    
    virtual void execute(Bug b);
    virtual void parse(string args); 
    
private:

    World w;

};


class I_direction: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    tdirection d;
    tstate x;
    tstate y;
    
};


class I_drop: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    tstate z;
    
};


class I_flip: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
    void randomint();
    
private:

    int p;
    tstate x;
    tstate y;
    int seed;
    
};


class I_mark: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    int m;
    tstate z;
    
};


class I_move: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    tstate x;
    tstate y;
    
};

class I_pickup: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
    
private:
    
    tstate x;
    tstate y;
    
};

class I_sense: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
    int randomint();
    
private:
    
    int p;
    tstate x;
    tstate y;
    int seed;
    
};

class I_turn: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    tleftright m;
    tstate z;
    
};

class I_unmark: public Instruction{

public:
    
    void execute(Bug b);
    void parse(string args);
      
private:
    
    int m;
    tstate z;
    
};

class Marker{

public:
    
    Marker();
    
    void set_marker(tmark mark, tcolor col);
    void clear_marker(tmark mark, tcolor col);
    
    bool check_marker(tmark mark, tcolor col);
    bool check_other_marker(tcolor col);
        
private:
    
    int bits;
    
};

class Program{
    
public:
    
    Program(string filename);
    void step(Bug b);
    
private:

    int id;
};



#endif /* ALLCLASSES_H */

