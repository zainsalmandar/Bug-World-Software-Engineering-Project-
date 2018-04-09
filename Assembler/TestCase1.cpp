#include "Labels.h"
#include "string"

using namespace std;

class Labels: public CppUnit:Test {
private:
    Labels *x_1, *x_2, *x_3, *x_4, *x_5, *x_6;
public:
    void setUp() {
    x_1=int x1;
    x_2=int x2;
    x_3=int x3;
    x_4=string x4;
    x_5=string x5;
    x_6=string x6;
    }

    void Delete() {
    delete x_1;
    delete x_2;
    delete x_3;
    delete x_4;
    delete x_5;
    delete x_6;
    }

    void Push_label() {

    CPPUNIT_ASSERT(resolve_lineof(*x_4) == add_label(*x4,*x_1));
    CPPUNIT_ASSERT(resolve_lineof(*x_5) == add_label(*x5,*x_2));
    CPPUNIT_ASSERT(resolve_lineof(*x_6) == add_label(*x6,*x_3));
    }

    void Push_goto() {
    CPPUNIT_ASSERT(resolve_goto(*x_1) == add_goto(*x4,*x_1));
    CPPUNIT_ASSERT(resolve_goto(*x_2) == add_goto(*x5,*x_2));
    CPPUNIT_ASSERT(resolve_goto(*x_3) == add_goto(*x6,*x_3));
    exception line_of(!*x_4)== error("Does not exist");
    }
};

CppUnit::TestSuite suite;
CppUnit::TestResult test1;
suite.addTest( new CppUnit::TestCaller<Labels> ("Push_label",&Labels::Push_label));
suite.addTest( new CppUnit::TestCaller<Labels> ("Push_goto",&Labels::Push_goto));
suit.run(&test1);
