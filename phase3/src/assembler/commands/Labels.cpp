#include "Labels.h"
#include <string>
#include <iostream>
#include <map>

Labels::Labels() {
    labels = std::map<int, std::string>();
    gotos = std::map<int, std::string>();
}

int Labels::line_of(std::string label) {
    return 0;
}

void Labels::add_label(std::string label, int line) {
    labels[line] = label;
}

void Labels::add_goto(std::string label, int line) {
    gotos[line] = label;
}

int Labels::resolve_goto(int line) {
    return 0;
}
