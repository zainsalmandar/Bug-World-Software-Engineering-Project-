#ifndef LABELS_H_
#define LABELS_H_

#include <string>
#include <map>

class Labels{
    private:
        // stores the labels
        std::map<int, std::string> labels;
        // stores the gotos
        std::map<int, std::string> gotos;
    public:
        //Constructor
        Labels();

        // Methods
        int line_of(std::string label);
        void add_label(std::string label, int line);
        void add_goto(std::string label, int line);
        int resolve_goto(int line);
};

#endif