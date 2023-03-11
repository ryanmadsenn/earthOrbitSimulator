#include "fakeSimulator.h"
#include "gps.h"
#include "hubble.h"
#include "crewDragon.h"
#include "sputnik.h"
#include "starlink.h"
#include <cassert>

using namespace std;


class TestSimulator {
    TestSimulator();

    void run();

    void testCheckForCollisions_false();
    void testCheckForCollisions_true();
    void testCheckForCollisions_close();
    void testCheckForCollisions_closeMiss();

    void testHandleCollision();

    void testUpdateObjects();
};