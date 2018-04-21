#include "Marker.h"
#include <stdexcept>

void Marker::set_marker(const mark_t& mark, const color_t& col){
    if(mark.val < 0 || mark.val > 5 ||  col.val < 0 || col.val > 1){
        throw std::runtime_error("Value not in range");
    }
    /*if black user higher 6 bits
     *set bit at bit position = mark.val    
    */
    if(col.val == 0){
        bits |= (1 << (11-mark.val));
    }
    /*if red use lower 6 bits
     *set bit at bit position = mark.val
     */
    else {
        bits |= (1 << (5-mark.val));
    }
}

void Marker::clear_marker(const mark_t& mark, const color_t& col){
    if(mark.val < 0 || mark.val > 5 ||  col.val < 0 || col.val > 1){
        throw std::runtime_error("Value not in range");
    }

    if(col.val == 0){
        bits &= ~(1 << (11-mark.val));
    }
    else {
        bits &= ~(1 << (5-mark.val));
    }
}

bool Marker::check_marker(const mark_t& mark, const color_t& col){
    if(mark.val < 0 || mark.val > 5 ||  col.val < 0 || col.val > 1){
        throw std::runtime_error("Value not in range");
    }

    if(col.val == 0){
        return (bits & (1 << (11-mark.val))); 
    }
    
    else {
        return (bits & (1 << (6-mark.val)));
    }
}

bool Marker::check_other_marker(const color_t& col){
    if(col.val < 0 || col.val > 1){
        throw std::runtime_error("Value not in range");
    }

    //if black check if any lower 6 bits are set
    if(col.val == 0){
        return (bits >= 1 && bits < 64);
    }
    //if red check if any higher 6 bits are set
    else {
        return (bits >= 64);
    }
}