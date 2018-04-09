#include "Labels.h"
#include "I_default.h"
#include "string"

using namespace std;

class Labels::public I_*::class I_default {
private:
    Labels *x_1, *x_2, *x_3

    void setup() {
    x_1= string x1;
    x_2= string x2;
    x_3= int x3;
    }

    void Delete() {
    delete x_1;
    delete x_2;
    delete x_3;
    }

    void read() {
    CPPUNIT_ASSERT(parse(*x_1,*x_3) == read(*x_2));
    CPPUNIT_ASSERT(parse(!*x_1,*x_3) == read(*x_2));
    }

    void default() {
        CPPUNIT_ASSERT(lineof(*x_1)==parse(*x_1,*x_3));
        CPPUNIT_ASSERT(resolve_goto(*x_1)==parse(*x_1,*x_3));
        }

};
CppUnit::TestSuite suite;
CppUnit::TestResult test2;
suite.addTest( new I_*::TestCaller<Labels> ("read",&Labels::read));
suite.addTest( new I_*::TestCaller<Labels> ("default",&Labels::default));
suit.run(&test2);
