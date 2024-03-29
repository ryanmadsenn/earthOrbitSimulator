#pragma once
#include "../simulator/fakeSimulator.h"
#include "../orbitingObject/satellite/gps/gps.h"
#include "../orbitingObject/satellite/hubble/hubble.h"
#include "../orbitingObject/satellite/sputnik/sputnik.h"
#include "../orbitingObject/satellite/starlink/starlink.h"
#include "../orbitingObject/satellite/crewDragon/crewDragon.h"
#include <cassert>

using namespace std;


class TestSimulator {
public:
    TestSimulator();

    void run();
    void testCheckForCollisions_false();
    void testCheckForCollisions_true();
    void testCheckForCollisions_close();
    void testCheckForCollisions_closeMiss();
    void testHandleCollision();
    void testUpdateObjects();
};