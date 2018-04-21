#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

#include <fstream>

#include <iostream>

#define private public

#include "../src/assembler/Program.h"

class ProgramTest : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (ProgramTest);
    CPPUNIT_TEST (constructorTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void constructorTest (void);
};

CPPUNIT_TEST_SUITE_REGISTRATION (ProgramTest);

void ProgramTest::constructorTest() {
    Program test("test/test.buggy");
    CPPUNIT_ASSERT(test.line == 0);
    CPPUNIT_ASSERT(test.lines.front() == "home:");
    test.lines.pop_front();
    CPPUNIT_ASSERT(test.lines.front() == "    turn left");
}

void ProgramTest::setUp() {
}

void ProgramTest::tearDown() {
    
}

int main (int argc, char* argv[])
{
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