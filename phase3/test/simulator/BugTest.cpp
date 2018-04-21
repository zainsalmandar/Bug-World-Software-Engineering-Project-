#include "BugTest.h"
#include "../../src/simulator/Bug.h"

CPPUNIT_TEST_SUITE_REGISTRATION(BugTest);

void BugTest::testConstructor() {
    color_t col;
    col.val = 0;
    int progId = 1;
    int resting = 10;
 
    CPPUNIT_ASSERT_NO_THROW(Bug testBug(col, progId, resting));
    
    Bug testBug(col, progId, resting);
    CPPUNIT_ASSERT(testBug.get_color().val == col.val);
    CPPUNIT_ASSERT(testBug.get_progid() == progId);
}

void BugTest::testRest(){
    color_t col;
    col.val = 1;
    int progId = 1;
    int resting = 10;
    
    Bug testBug(col, progId, resting);

    CPPUNIT_ASSERT(testBug.rested() == false);
    
    testBug.start_resting();
    
    CPPUNIT_ASSERT(testBug.rested() == true);
}

void BugTest::testGetters(){
    int progId = 1;
    int resting = 10;
    bool food = true;

    color_t col;
    col.val = 1;
    
    state_t state;
    state.val = 2;

    direction_t dir;
    dir.val = 5;

    position_t pos;
    pos.x = 0;
    pos.y = 0;

    Bug testBug(col, progId, resting);

    testBug.set_state(state);
    testBug.set_direction(dir);
    testBug.set_position(pos);
    testBug.set_food(food);

    CPPUNIT_ASSERT(testBug.get_progid() == 1);
    CPPUNIT_ASSERT(testBug.get_color().val == col.val);
    CPPUNIT_ASSERT(testBug.get_state().val == state.val);
    CPPUNIT_ASSERT(testBug.get_direction().val == dir.val);
    CPPUNIT_ASSERT(testBug.get_position().x == pos.x);
    CPPUNIT_ASSERT(testBug.get_position().y == pos.y);
    CPPUNIT_ASSERT(testBug.has_food() == true);
}

void BugTest::testSetters(){
    int progId = 1;
    int resting = 10;

    state_t state;
    color_t col;
    position_t pos;
    direction_t dir;

    col.val = 0;

    Bug testBug(col, progId, resting);

    state.val = -1;

    CPPUNIT_ASSERT_THROW(testBug.set_state(state), std::runtime_error);

    state.val = 10000;
    CPPUNIT_ASSERT_THROW(testBug.set_state(state), std::runtime_error);

    dir.val = -1;
    CPPUNIT_ASSERT_THROW(testBug.set_direction(dir), std::runtime_error);

    dir.val = 6;

    CPPUNIT_ASSERT_THROW(testBug.set_direction(dir), std::runtime_error);
    
    state.val = 1;
    dir.val = 1;
    pos.x = 0;
    pos.y = 0;
    
    testBug.set_state(state);
    testBug.set_direction(dir);
    testBug.set_position(pos);

    CPPUNIT_ASSERT(testBug.get_state().val == state.val);
    CPPUNIT_ASSERT(testBug.get_direction().val == dir.val);
    CPPUNIT_ASSERT(testBug.get_position().x == pos.x);
    CPPUNIT_ASSERT(testBug.get_position().y == pos.y);
}

void BugTest::testKill(){
    int progId = 1;
    int resting = 10;

    color_t col;
    col.val = 1;

    Bug testBug(col, progId, resting);

    CPPUNIT_ASSERT(testBug.is_dead() == false);

    testBug.kill();

    CPPUNIT_ASSERT(testBug.is_dead() == true);

    CPPUNIT_ASSERT_THROW(testBug.kill(), std::runtime_error);
}




