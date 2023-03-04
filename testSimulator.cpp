#include "testSimulator.h"

void TestSimulator::run() {
    testCheckForCollisions();
    testHandleCollision();
    testUpdateObjects();
}

void TestSimulator::testCheckForCollisions() {
    // Test 1: No collisions
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(-100, -100));

    //Exercise and Verify.
    assert(!fakeSimulator.checkForCollisions());

    // Teardown.
    fakeSimulator.clearOrbitingObjects();

    // Test 2: Obvious Collision
    // Setup.
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 100));

    // Exercise and Verify.
    assert(fakeSimulator.checkForCollisions());

    // Teardown.
    fakeSimulator.clearOrbitingObjects();

    // Test 3: Close collision
    // Setup.
    // Since both GPS' have a radius of 12, we place them
    // 23 units apart to make sure the collision is detected.
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 123));

    // Exercise and Verify.
    assert(fakeSimulator.checkForCollisions());

    // Teardown.
    fakeSimulator.clearOrbitingObjects();

    // Test 4: Close miss
    // Setup.
    // Since both GPS' have a radius of 12, we place them
    // 24 units apart to make sure the collision is not detected.
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 124));

    // Exercise and Verify.
    assert(!fakeSimulator.checkForCollisions());

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}

void TestSimulator::testHandleCollision() {
    // Test 1: Two GPS's
    // Setup.
    FakeSimulator fakeSimulator;
    fakeSimulator.addOrbitingObject(new GPS(100, 100));
    fakeSimulator.addOrbitingObject(new GPS(100, 100));

    // Exercise.
    fakeSimulator.handleCollisions();

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
        assert(fakeSimulator.getOrbitingObjects()[i]->getX() == 100);
        assert(fakeSimulator.getOrbitingObjects()[i]->getY() == 100);
    }

    // Teardown.
    fakeSimulator.clearOrbitingObjects();
}


