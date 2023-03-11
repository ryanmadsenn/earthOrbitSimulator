#include "../orbitingObject/orbitingObject.h"
#include "../orbitingObject/satellite/gps/gps.h"
#include "../orbitingObject/satellite/hubble/hubble.h"
#include "../orbitingObject/satellite/crewDragon/crewDragon.h"
#include "../orbitingObject/satellite/sputnik/sputnik.h"
#include "../orbitingObject/satellite/starlink/starlink.h"
#include "../orbitingObject/dreamchaser/dreamChaser.h"
#include "../uiInteract.h"
#include "../projectile.h"
#include "../earth.h"
#include "../star.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Simulator {
protected:
    vector<Star> stars;
    Earth earth;
    DreamChaser dreamChaser;
    vector<OrbitingObject*> orbitingObjects;
    vector<Projectile> projectiles;
    Interface *pUI;

public:
    Simulator();

    virtual void initialize();

    void update();

    void handleInput();

    virtual bool checkForCollisions();

    virtual void handleCollision();

    virtual void updateObjects();

    void addOrbitingObject(OrbitingObject *pObj);

    vector<OrbitingObject*> getOrbitingObjects();

    void clearOrbitingObjects();

    void draw();
};