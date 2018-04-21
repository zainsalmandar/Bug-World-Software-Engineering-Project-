#ifndef MARKER_H
#define MARKER_H

#include "ExposedTypes.h"

class Marker{
private:
    int bits;
public:
    Marker(){bits = 0;};
    void set_marker(const mark_t& mark, const color_t& col);
    void clear_marker(const mark_t& mark, const color_t& col);
    
    bool check_marker(const mark_t& mark, const color_t& col);
    bool check_other_marker(const color_t& col);
    
};
#endif /* MARKER_H */

