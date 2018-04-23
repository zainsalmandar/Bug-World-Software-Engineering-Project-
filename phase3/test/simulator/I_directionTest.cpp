#include "I_directionTest.h"
#include ".../../src/simulator/commands/I_direction.h"

CPPUNIT_TEST_SUITE_REGISTRATION(I_directionTest);

void I_directionTest::testDConstructor {
    I_direction testclass;
    CPP_ASSERT(testclass.getWorld() == NULL);

}

/*void I_direction::testLoad() {
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
}*/