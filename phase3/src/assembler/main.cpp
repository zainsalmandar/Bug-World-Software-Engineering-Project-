#include "Program.h"

int main(int argc, const char *argv[]) {
	Program assembler(argv[1]);
	assembler.process();
    return 0;
}