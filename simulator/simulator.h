#include "orbitingObject/orbitingObject.h"

class Simulator {
protected:
    vector<Star> stars;
    Earth earth;
    DreamChaser dreamChaser;
    vector<OrbitingObject *> orbitingObjects;
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

    void clearOrbitingObjects();

    void draw();
};