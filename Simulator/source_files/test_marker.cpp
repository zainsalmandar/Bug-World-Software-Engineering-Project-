/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Test.cpp
 * Author: bryann
 *
 * Created on April 9, 2018, 9:56 PM
 */

#include <cstdlib>
#include "Marker.h"
#include "allClasses.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    
    Marker one();
    
    //Proper Input
    one.set_marker(0, 1);
    one.clear_marker(0, 1);
    one.check_marker(0, 1);
    one.check_other_marker(1);
    
    //Erroneous Input
    one.set_marker(7, 7);
    one.clear_marker(7, 7);
    one.check_marker(7, 7);
    one.check_other_marker(7);
    
    //Mixed Input
    one.set_marker(0, 7);
    one.clear_marker(0, 7);
    one.check_marker(0, 7);
    one.check_other_marker(7);
    
        
    return 0;

}
