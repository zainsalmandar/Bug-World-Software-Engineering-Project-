/* 
 * File:   Marker.cpp
 */

#include "Marker.h"

/* Color 0 represents red bugs
 * Color 1 represents black bugs
 * 
 * To ensure the uniqueness of of mark and color combinations, the first
 * set of combinations will be assigned to red bugs and run between
 * 0-5. 
 * 
 * For black bugs, the set of combinations will be assigned to black bugs 
 * and run between 6-11.
 */

using namespace std;


Marker::Marker(){

};

Marker::~Marker(){

};

Marker::set_marker(tmark mark, tcolor col){
    if(mark.mark <0 || mark.mark > 5){
        
        cerr << "Invalid mark input!" << endl;    
        
    }else if(col.color != 0 && col.color!= 1){
        
        cerr << "Invalid color input!" <<endl;
        
    }else{
    
        if(col.color == 0){
            this->bits = mark.mark;
        }else{
            this->bits = mark.mark + 6;
        }
        
    }

};

Marker::clear_marker(tmark mark, tcolor col){
    if(mark.mark <0 || mark.mark > 5){
        cerr << "Invalid mark input!" << endl;        
    }
    
    if(col.color != 0 && col.color!= 1){
        
        cerr << "Invalid color input!" <<endl;
        
    }else{
    
        this->bits= -1;
    
    }

};

Marker::check_marker(tmark mark, tcolor col){
        if(mark.mark <0 || mark.mark > 5){
        cerr << "Invalid mark input!" << endl;        
    }
    
    if(col.color != 0 && col.color!= 1){
        
        cerr << "Invalid color input!" <<endl;
        
    }else{
    
        return this->bits == mark.mark || this->bits == mark.mark + 6;
        
    }

};

Marker::check_other_marker(tcolor col){
    
    if(col.color != 0 && col.color!= 1){
        cerr << "Invalid color input!" <<endl;
    }

};


