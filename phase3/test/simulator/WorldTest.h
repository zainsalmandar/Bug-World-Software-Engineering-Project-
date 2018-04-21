#ifndef WORLDTEST_H
#define WORLDTEST_H

#include <cppunit/extensions/HelperMacros.h>

class WorldTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(WorldTest);

    CPPUNIT_TEST(testLoad);
    CPPUNIT_TEST(testExecuteCycle);
    CPPUNIT_TEST(testGetCell);
    CPPUNIT_TEST(testAdjacent);
    CPPUNIT_TEST(testOtherColor);
    CPPUNIT_TEST(testWinner);
    CPPUNIT_TEST(testStats);
    CPPUNIT_TEST(testError);
    CPPUNIT_TEST(testLog);
    CPPUNIT_TEST_SUITE_END();

public:
    WorldTest(){};
    virtual ~WorldTest(){};
    void setUp(){};
    void tearDown(){};

private:
    void testLoad();
    void testExecuteCycle();
    void testGetCell();
    void testAdjacent();
    void testOtherColor();
    void testWinner();
    void testStats();
    void testError();
    void testLog();
};

#endif /* WORLDTEST_H */

