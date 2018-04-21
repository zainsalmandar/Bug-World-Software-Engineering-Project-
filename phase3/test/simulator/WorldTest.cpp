#include "WorldTest.h"
#include ".../../src/simulator/World.h"

CPPUNIT_TEST_SUITE_REGISTRATION(WorldTest);

void WorldTest::testLoad() {
    World testWorld;
    std::string file1 = 'doesNotExist1.txt';
    std::string file2 = 'doesNotExist2.txt';
    std::string file3 = 'doesNotExist3.txt';
    bool exceptionThrown = false;
    
    try{
        testWorld.load(file1, file2, file3);
    }
    catch(std::runtime_error){
        exceptionThrown = true;
    }
    
    if(!exceptionThrown){
        CPPUNIT_FAIL("No exception thrown on invalid filename");
    } 
    
    file1 = "world.txt";
    file2 = "blackbug.txt";
    file3 = "redbug.txt";
    CPPUNIT_ASSERT_NO_THROW(testWorld.load(file1, file2, file3));   
}