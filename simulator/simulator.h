#pragma once

#include "../orbitingObject/orbitingObject.h"
#include "../orbitingObject/satellite/gps/gps.h"
#include "../orbitingObject/satellite/hubble/hubble.h"
#include "../orbitingObject/satellite/crewDragon/crewDragon.h"
#include "../orbitingObject/satellite/sputnik/sputnik.h"
#include "../orbitingObject/satellite/starlink/starlink.h"
#include "../orbitingObject/dreamchaser/dreamchaser.h"
#include "../uiInteract/uiInteract.h"
#include "../projectile/projectile.h"
#include "../earth/earth.h"
#include "../star/star.h"
#include <iostream>
#include <vector>
#include <string>
#include "../physics/physics.h"

using namespace std;

class Simulator {
protected:
    vector<Star> stars;
    Earth earth;
    DreamChaser * dreamChaser;
    vector<OrbitingObject*> orbitingObjects;
    vector<Projectile*> projectiles;
    Interface const *pUI;
    Position const *ptUpperRight;

public:
    Simulator() = default;

    Simulator(const Position *ptUpperRight, const Interface *pUI);

    virtual void initialize();

    void update();

    void handleInput();

    virtual bool checkForCollisions();

    virtual void handleCollision(OrbitingObject * obj1, int obj1index, OrbitingObject * obj2, int obj2index);

    virtual void updateObjects();

    void addOrbitingObject(OrbitingObject *pObj);

    vector<OrbitingObject*> getOrbitingObjects();

    void clearOrbitingObjects();

    void draw();
};