#include "testSimulator.h"

TestSimulator::TestSimulator() {}

void TestSimulator::run() {
    testCheckForCollisions_false();
    testCheckForCollisions_true();
    testCheckForCollisions_close();
    testCheckForCollisions_closeMiss();
    testHandleCollision();
    testUpdateObjects();
    cout << "TestSimulator Tests Passed!" << endl;
}

// Test 1: No collisions
void TestSimulator::testCheckForCollisions_false() {
    
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(-100, -100));

    // Exercise 
    bool isCollision = fakeSimulator.checkForCollisions();

    // Verify.
    assert(!isCollision);

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}

// Test 2: Obvious Collision
void TestSimulator::testCheckForCollisions_true() {
    
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 100));

    // Exercise and Verify.
    bool isCollision = fakeSimulator.checkForCollisions();

    // Verify.
    assert(isCollision);

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}

// Test 3: Close collision
void TestSimulator::testCheckForCollisions_close() {
    
    // Setup.
    // Since both GPS' have a radius of 12, we place them
    // 23 units apart to make sure the collision is detected.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 123));

    // Exercise and Verify.
    bool isCollision = fakeSimulator.checkForCollisions();

    // Verify.
    assert(isCollision);

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}

// Test 4: Close miss
void TestSimulator::testCheckForCollisions_closeMiss() {
    
    // Setup.
    // Since both GPS' have a radius of 12, we place them
    // 24 units apart to make sure the collision is not detected.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 124));

    // Exercise 
    bool isCollision = fakeSimulator.checkForCollisions();

    // Verify.
    assert(!isCollision);

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}

// Test 5: Two GPS's 
void TestSimulator::testHandleCollision() {
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 100));

    // Exercise.
    fakeSimulator.handleCollision(fakeSimulator.getOrbitingObjects()[0], 0, fakeSimulator.getOrbitingObjects()[1], 1);

    // Verify.
    assert(fakeSimulator.getOrbitingObjects().size() == 0);

    // Teardown.
    fakeSimulator.clearOrbitingObjects();

}

void TestSimulator::testUpdateObjects() {
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(0, 0));
    fakeSimulator.addOrbitingObject(new Hubble(0, 0));
    fakeSimulator.addOrbitingObject(new CrewDragon(0, 0));
    fakeSimulator.addOrbitingObject(new Starlink(0, 0));
    fakeSimulator.addOrbitingObject(new Sputnik(0, 0));

    // Exercise.
    // With our overloaded updateObjects() method, we will
    // set the position of each object to (100, 100).
    fakeSimulator.updateObjects();

    // Verify.
    for (int i = 0; i < fakeSimulator.getOrbitingObjects().size(); i++) {
        assert(fakeSimulator.getOrbitingObjects()[i]->getPosition().getPixelsX() == 100);
        assert(fakeSimulator.getOrbitingObjects()[i]->getPosition().getPixelsY() == 100);
    }

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}


