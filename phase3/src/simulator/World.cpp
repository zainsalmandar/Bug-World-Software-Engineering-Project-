#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
#include "World.h"

int World::log_num = 0;

void World::load(const std::string& world, const std::string& black_bug_file, const std::string& red_bug_file){
    
    char c;
    std::string length, width;
    int l, w, i, redBugs, blackBugs;
    std::ifstream WorldFile;
    color_t black, red;
    black.val = 0;
    red.val = 1;
    int resting = 10;
    int red_progId = 0, black_progId = 0;
  
    WorldFile.open(world);
    
    if(!WorldFile.is_open()){
        throw std::runtime_error("Error opening files");
    }
    else {
        //first two lines are the length and the width
        getline(WorldFile, length);
        getline(WorldFile, width);
        l = std::stoi(length);
        w = std::stoi(width);
        
        //create length*width instances of cells
        int ii, jj;
        for(ii = 0; ii < l; ii++) {
            try
            {
              cells = new Cell**[l];
            }
            catch (std::bad_alloc& ba)
            {
              std::cerr << "bad_alloc caught: " << ba.what() << '\n';
            }
            for(jj = 0; jj < w; jj++) {
                try
                {
                    cells[ii] = new Cell*[w];
                }
                catch (std::bad_alloc& ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                }
            } 
        }
        
        
        //count red and black bugs
        int redBugs = blackBugs = 0;
        
        int x, y;
        x = y = 0;
        while(WorldFile.get(c)){
            if (c == '\n')
                x++;
            //create cell for every char symb
            cells[x][y] = new Cell(c);
            if( c == '+'){
                redBugs++;
            }
            else if( c  == '-'){
                blackBugs++;
            }
            y++;
        }
        WorldFile.close();
        
        //create instances of red and black bugs
        red_bugs  = new Bug*[redBugs];
        black_bugs = new Bug*[blackBugs];
        for(i=0;i<redBugs;i++){
            red_bugs[i] = new Bug(red, red_progId++, resting);
        }
        for(i=0;i<blackBugs;i++){
            black_bugs[i] = new Bug(black, black_progId++, resting);
        }
        
        /* go through the cells
         * if cell is black home area 
         * populate cell with black bug
         * if cell is red home area
         * populate cell with red bug
         */
        int j = 0, k = 0;
        for(ii=0; i< l;ii++){
            for(jj = 0; jj < w; jj++) {
                if (cells[ii][jj]->is_red_home_area()){
                    cells[ii][jj]->set_occupant(red_bugs[j++]);
                }
                else if(cells[ii][jj]->is_black_home_area()){
                    cells[ii][jj]->set_occupant(black_bugs[k++]);
                }
            }
            
        }
       
        programs = new Program*[2];
        programs[0]  = new Program(black_bug_file);
        programs[1]  = new Program(red_bug_file);
    }
}

void World::execute_cycle() {
    
}

Cell* World::get_cell(position_t& pos) const {
    return cells[pos.x][pos.y];
}

position_t World::adjacent(const direction_t& dir, const position_t& pos) const {
    if (dir.val < 0 && dir.val > 5)
        this->error("Direction: out of range!!!");
    position_t newpos;
    if(dir.val == 0) {
        newpos.x = pos.x + 1;
        newpos.y = pos.y;
        return newpos;
    }
    else if(dir.val == 1) {
        if (pos.y % 2 == 0) {
            newpos.x = pos.x;
            newpos.y = pos.y + 1;
        }
        else {
            newpos.x = pos.x + 1;
            newpos.y = pos.y + 1;
        }
        return newpos;
    }
    else if(dir.val == 2) {
        if (pos.y % 2 == 0) {
            newpos.x = pos.x - 1;
            newpos.y = pos.y + 1;
        }
        else {
            newpos.x = pos.x;
            newpos.y = pos.y + 1;
        }
        return newpos;
    }
    else if(dir.val == 3) {
        newpos.x = pos.x - 1;
        newpos.y = pos.y;
        return newpos;
    }
    else if(dir.val == 4) {
        if (pos.y % 2 == 0) {
            newpos.x = pos.x - 1;
            newpos.y = pos.y - 1;
        }
        else {
            newpos.x = pos.x;
            newpos.y = pos.y - 1;
        }
        return newpos;
    }
    else {
        if (pos.y % 2 == 0) {
            newpos.x = pos.x;
            newpos.y = pos.y - 1;
        }
        else {
            newpos.x = pos.x + 1;
            newpos.y = pos.y - 1;
        }
        return newpos;
    }
}

color_t World::other_color(const color_t& col) const {
    color_t newcol;
    if(col.val < 0 || col.val > 1)
        this->error("Color value: out of range!");
    if(col.val == 1)
        newcol.val = 0;
    else
        newcol.val = 1;;
    return newcol;
}

int World::red_food() const {
    int i, j, food = 0;
    for(i = 0; i < length; i++){
        for (j = 0; j < width; j++){
            if(cells[i][j]->is_red_home_area()){
                food += cells[i][j]->get_food();
            }
        }         
    }
    return food;
}

int World::black_food() const {
    int i, j, food = 0;
    for(i = 0; i < length; i++){
        for (j = 0; j < width; j++){
            if(cells[i][j]->is_black_home_area()){
                food += cells[i][j]->get_food();
            }
        }         
    }
    return food;
}

int World::red_count() const {
    int bugs, i, j;
    for(i = 0; i < length; i++){
        for (j = 0; j < width; j++){
            Bug *curBug;
            curBug = cells[i][j]->get_occupant();
            if (curBug == NULL || curBug->is_dead() || curBug->get_color().val == 0)
                continue;
            bugs++;
        }
    }
    return bugs;
}

int World::black_count() const {
    int bugs, i, j;
    for(i = 0; i < length; i++){
        for (j = 0; j < width; j++){
            Bug *curBug;
            curBug = cells[i][j]->get_occupant();
            if (curBug == NULL || curBug->is_dead() || curBug->get_color().val == 1)
                continue;
            bugs++;
        }
    }
    return bugs;
}

color_t* World::winner() const {
    color_t *win;
    if (this->red_food() > this->black_food())
        win->val = 1;
    else if (this->red_food() < this->black_food())
        win->val = 0;
    else 
        if(this->red_count() > this->black_count())
            win->val = 1;
        else if (this->red_count() < this->black_count())
            win->val = 0;
        else {
            std::cout << "A tie!!!" << std::endl;
            return NULL;
        }
    return win;      
}

void World::error(const std::string& msg) const {
    throw std::runtime_error(msg);
}

void World::log(std::string& format) const {
    log_num++;
    std::ofstream out("log.txt");
    if(!out.is_open()){
        throw std::runtime_error("Error opening files");
    }
    out << "#" << log_num << " -> " << "Red food: " << this->red_food() 
            << "; Black food: " << this->black_food() << "; Red count: "
            << this->red_count() << "; Black count: " << this->black_count()
            << "; WINNER: " << this->winner()->val << "black(0), red(1)" << std::endl;
    out.close();
}

World::~World(){
    int i, j;
    for(i = 0; i < length; i++) {
        for(j = 0; j < width; j++) {
            delete[] cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
    
    delete[] programs[0];
    delete[] programs[1];
    delete[] programs;
    
    int s1, s2;
    s1 = sizeof(red_bugs)/sizeof(Bug);
    s2 = sizeof(black_bugs)/sizeof(Bug);
    
    for(i = 0; i < s1; i++) {
        delete[] red_bugs[i];
    }
    delete[] red_bugs;
    
    for(i = 0; i < s2; i++) {
        delete[] black_bugs[i];
    }
    delete[] black_bugs;
}

