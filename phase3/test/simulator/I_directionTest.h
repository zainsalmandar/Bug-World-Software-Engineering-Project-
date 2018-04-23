#ifndef I_DIRECTIONTEST_H
#define I_DIRECTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class I_directionTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(I_directionTest);

    /*CPPUNIT_TEST(testDConstructor);
    CPPUNIT_TEST(testPConstructor);
    CPPUNIT_TEST(testExecute);
    CPPUNIT_TEST(testParse);
    CPPUNIT_TEST_SUITE_END();*/

public:
    I_directionTest(){};
    virtual ~I_directionTest(){};
    void setUp(){};
    void tearDown(){};

private:
    void testDConstructor();
    void testPConstructor();
    void testExecute();
    void testParse();
};

#endif /* WORLDTEST_H */

