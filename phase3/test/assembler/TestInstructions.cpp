#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

#include <iostream>

#define private public
#define protected public

#include "../src/assembler/commands/Labels.h"
#include "../src/assembler/commands/Instruction.h"
#include "../src/assembler/commands/I_default.h"
#include "../src/assembler/commands/I_direction.h"
#include "../src/assembler/commands/I_drop.h"
#include "../src/assembler/commands/I_flip.h"
#include "../src/assembler/commands/I_mark.h"
#include "../src/assembler/commands/I_move.h"
#include "../src/assembler/commands/I_pickup.h"
#include "../src/assembler/commands/I_sense.h"
#include "../src/assembler/commands/I_turn.h"
#include "../src/assembler/commands/I_unmark.h"

class TestCommands : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (TestCommands);
    CPPUNIT_TEST (testI_default);
    CPPUNIT_TEST (testI_direction);
    CPPUNIT_TEST (testI_drop);
    CPPUNIT_TEST (testI_flip);
    CPPUNIT_TEST (testI_mark);
    CPPUNIT_TEST (testI_pickup);
    CPPUNIT_TEST (testI_turn);
    CPPUNIT_TEST (testI_unmark);
    CPPUNIT_TEST (testI_sense);
    CPPUNIT_TEST_SUITE_END ();

    private:
        Labels list;

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void testI_default (void);
        void testI_direction (void);
        void testI_drop (void);
        void testI_flip (void);
        void testI_mark (void);
        void testI_move (void);
        void testI_pickup (void);
        void testI_turn (void);
        void testI_unmark (void);
        void testI_sense (void);
};

CPPUNIT_TEST_SUITE_REGISTRATION (TestCommands);

void TestCommands::setUp() {
    list = Labels();
}

void TestCommands::tearDown() {
    
}

void TestCommands::testI_default() {
    I_default test(list);
    int res = test.parse("goto default", 1);
    CPPUNIT_ASSERT(test.line == 1);
    CPPUNIT_ASSERT(res == 1);
}

void TestCommands::testI_direction() {
    // test correct parsing
    I_direction test(list);
    int res = test.parse("direction 4 else home", 2);
    CPPUNIT_ASSERT(test.line == 2);
    CPPUNIT_ASSERT(res == 3);
    CPPUNIT_ASSERT(test.dir == 4);
    CPPUNIT_ASSERT(test.on_fail == "home");
    // test errors
    test = I_direction(list);
    res = test.parse("direction -1 else home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_direction(list);
    res = test.parse("direction 0 els2e home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_direction(list);
    res = test.parse("direction 0", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_drop() {
    I_drop test(list);
    int res = test.parse("drop", 1);
    CPPUNIT_ASSERT(test.line == 1);
    CPPUNIT_ASSERT(res == 2);
}

void TestCommands::testI_flip() {
    // test correct parsing
    I_flip test(list);
    int res = test.parse("flip 4 else home2", 3);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.p == 4);
    CPPUNIT_ASSERT(test.on_fail == "home2");
    // test errors
    test = I_flip(list);
    res = test.parse("flip 0 else home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_flip(list);
    res = test.parse("flip 2 els2e home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_flip(list);
    res = test.parse("flip 2", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_mark() {
    // test correct parsing
    I_mark test(list);
    int res = test.parse("mark 2", 3);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.mark == 2);
    // test errors
    test = I_mark(list);
    res = test.parse("mark -1", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_mark(list);
    res = test.parse("mark 6", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_mark(list);
    res = test.parse("mark", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_move() {
    // test correct parsing
    I_move test(list);
    int res = test.parse("move else home", 3);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.on_fail == "home");
    // test errors
    test = I_move(list);
    res = test.parse("move elbe home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_move(list);
    res = test.parse("move home", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_pickup() {
    // test correct parsing
    I_pickup test(list);
    int res = test.parse("pickup else home", 3);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.on_fail == "home");
    // test errors
    test = I_pickup(list);
    res = test.parse("pickup elbe home", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_pickup(list);
    res = test.parse("pickup home", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_sense() {
    // test correct parsing
    I_sense test(list);
    int res = test.parse("sense ahead food else home", 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(test.on_fail == "home");
    CPPUNIT_ASSERT(test.dir == "ahead");
    CPPUNIT_ASSERT(test.cond == "food");
    test = I_sense(list);
    res = test.parse("sense here marker 1 else run", 4);
    CPPUNIT_ASSERT(res == 5);
    CPPUNIT_ASSERT(test.line == 4);
    CPPUNIT_ASSERT(test.on_fail == "run");
    CPPUNIT_ASSERT(test.dir == "here");
    CPPUNIT_ASSERT(test.cond == "marker 1");
    // test errors
    test = I_sense(list);
    res = test.parse("sense behind marker 1 else run", 4);
    CPPUNIT_ASSERT(res == -1);
    test = I_sense(list);
    res = test.parse("sense ahead unknown else run", 4);
    CPPUNIT_ASSERT(res == -1);
    test = I_sense(list);
    res = test.parse("sense ahead home elbse run", 4);
    CPPUNIT_ASSERT(res == -1);
    test = I_sense(list);
    res = test.parse("sense ahead marker 100 else run", 4);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_turn() {
    // test correct parsing
    I_turn test(list);
    int res = test.parse("turn left", 3);
    CPPUNIT_ASSERT(test.line == 3);
    CPPUNIT_ASSERT(res == 4);
    CPPUNIT_ASSERT(test.lr == 0);
    // test errors
    test = I_turn(list);
    res = test.parse("turn right", 4);
    CPPUNIT_ASSERT(test.line == 4);
    CPPUNIT_ASSERT(res == 5);
    CPPUNIT_ASSERT(test.lr == 1);
    test = I_turn(list);
    res = test.parse("turn ahead", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_turn(list);
    res = test.parse("turn", 2);
    CPPUNIT_ASSERT(res == -1);
}

void TestCommands::testI_unmark() {
    // test correct parsing
    I_unmark test(list);
    int res = test.parse("unmark 2", 1);
    CPPUNIT_ASSERT(test.line == 1);
    CPPUNIT_ASSERT(res == 2);
    CPPUNIT_ASSERT(test.mark == 2);
    // test errors
    test = I_unmark(list);
    res = test.parse("mark -1", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_unmark(list);
    res = test.parse("mark 6", 2);
    CPPUNIT_ASSERT(res == -1);
    test = I_unmark(list);
    res = test.parse("mark", 2);
    CPPUNIT_ASSERT(res == -1);
}

int main (int argc, char* argv[]) {
    CPPUNIT_NS :: TestResult testresult;

    CPPUNIT_NS :: TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    CPPUNIT_NS :: BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CPPUNIT_NS :: TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS :: TestFactoryRegistry :: getRegistry ().makeTest ());
    testrunner.run (testresult);

    CPPUNIT_NS :: CompilerOutputter compileroutputter (&collectedresults, std::cerr);
    compileroutputter.write ();

    return collectedresults.wasSuccessful () ? 0 : 1;
}