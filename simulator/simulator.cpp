#include "simulator.h"

/*******************************************************
 *
 *******************************************************/
Simulator::Simulator(const Position *ptUpperRight, const Interface *pUI) {
    this->ptUpperRight = ptUpperRight;
    this->pUI = pUI;
    initialize();
}

/*******************************************************
 *
 *******************************************************/
void Simulator::initialize()
{
    // Create 200 stars.
    for (int i = 0; i < 200; i++) {
        Position pt = Position();
        pt.setPixelsX(ptUpperRight->getPixelsX() * random(-0.5, 0.5));
        pt.setPixelsY(ptUpperRight->getPixelsY() * random(-0.5, 0.5));
        stars.push_back(Star(pt, random(0, 224)));
    }

    // Create the earth.
    earth = Earth();

    // Create 6 GPS satellites.
    orbitingObjects.push_back(new GPS(Position( 0.0,          26560000.0  ), -3880.0,  0.0,      0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( 23001634.72,  13280000.0  ), -1940.0,  3360.18,  0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( 23001634.72,  -13280000.0 ),  1940.0,  3360.18,  0.0, 12.0)); 
    orbitingObjects.push_back(new GPS(Position( 0.0,          -26560000.0 ),  3880.0,  0.0,      0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( -23001634.72, -13280000.0 ),  1940.0,  -3360.18, 0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( -23001634.72, 13280000.0  ), -1940.0,  -3360.18, 0.0, 12.0));
     
    // Create 5 other orbiting objects.
    orbitingObjects.push_back(new Sputnik      (Position(-36515095.13, 21082000.0),  2050.0,  2684.68, 0.0, 4.0));
    orbitingObjects.push_back(new Hubble       (Position(0.0,          42164000.0),  3100.0,  0.0,     0.0, 10.0));
    orbitingObjects.push_back(new Starlink     (Position(0.0,         -13020000.0),  5800.0,  0.0,     0.0, 6.0));
    orbitingObjects.push_back(new CrewDragon   (Position(0.0,           8000000.0),  -7900.0, 0.0,     0.0, 7.0));
    dreamChaser = new DreamChaser(Position(-45000000.0,  45000000.0),  0.0,     -2000,   0.0, 10.0);
    orbitingObjects.push_back(dreamChaser);
};  

/*******************************************************
 *
 *******************************************************/
void Simulator::update() {
    handleInput();
    checkForCollisions();
    updateObjects();
    draw();
}

/*******************************************************
 *
 * @param pUI
 *******************************************************/
void Simulator::handleInput() {
    if (pUI->isRight()) {
        dreamChaser->rotate(true);
    }

    if (pUI->isLeft()) {
        dreamChaser->rotate(false);
    }

    if (pUI->isDown()) {
        dreamChaser->thrust();
    } else {
        dreamChaser->stopThrust();
    }

    if (pUI->isSpace()) {
        dreamChaser->shoot(&projectiles);
    }
}

/*******************************************************
 *
 * @return
 *******************************************************/
bool Simulator::checkForCollisions() {
    for (int i = 0; i < orbitingObjects.size(); i++) {
        for (int j = i + 1; j < orbitingObjects.size(); j++) {
            double distance = computeDistancePixels(*orbitingObjects[i]->getPosition(), *orbitingObjects[j]->getPosition());

            if (distance < orbitingObjects[i]->getRadius() + orbitingObjects[j]->getRadius()) {
                handleCollision(orbitingObjects[i], i, orbitingObjects[j], j);
                return true;
            }
        }

        for (int k = 0; k < projectiles.size(); k++) {
            double distance = computeDistancePixels(*orbitingObjects[i]->getPosition(), *projectiles[k]->getPosition());

            if (distance < orbitingObjects[i]->getRadius() ){

                orbitingObjects[i]->smash(&orbitingObjects);
                orbitingObjects[i] = nullptr;
                delete orbitingObjects[i];
                orbitingObjects.erase(orbitingObjects.begin() + i);
                return true;
            }
        }


    }


    return false;
}

/*******************************************************
 *
 * @param pObj1
 * @param obj1index
 * @param pObj2
 * @param obj2index
 *******************************************************/
void Simulator::handleCollision(OrbitingObject *pObj1, int obj1index, OrbitingObject *pObj2, int obj2index) {
//    cout << "Collision between " << pObj1->getType() << " and " << pObj2->getType() << endl;
    pObj1->smash(&orbitingObjects);
    pObj2->smash(&orbitingObjects);

    pObj1 = nullptr;
    delete pObj1;
    orbitingObjects.erase(orbitingObjects.begin() + obj1index);

    pObj2 = nullptr;
    delete pObj2;
    orbitingObjects.erase(orbitingObjects.begin() + obj2index - 1);
}

/*******************************************************
 *
 * @param pObj
 *******************************************************/
void Simulator::addOrbitingObject(OrbitingObject *pObj) {
    orbitingObjects.push_back(pObj);
}

/*******************************************************
 *
 * @return
 *******************************************************/
vector<OrbitingObject*> Simulator::getOrbitingObjects()
{
    return orbitingObjects;
}

/*******************************************************
 *
 *******************************************************/
void Simulator::clearOrbitingObjects() {
    orbitingObjects.clear();
}

/*******************************************************
 *
 *******************************************************/
void Simulator::draw() {
    for (int i = 0; i < stars.size(); i++)
        stars[i].draw();

    earth.draw();

    for (int i = 0; i < orbitingObjects.size(); i++) {
        orbitingObjects[i]->draw();
    }

    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->draw();
    }
}

/*******************************************************
 *
 *******************************************************/
void Simulator::updateObjects()
{
    // This hard coded value needed to come from physics.computeRotationSpeed()
    earth.updateAngle(computeRotationSpeed());

    for (int i = 0; i < orbitingObjects.size(); i++) {
        applyPhysics(orbitingObjects[i]);

        if (dynamic_cast<Fragment*>(orbitingObjects[i])) {
            Fragment *pFragment = dynamic_cast<Fragment*>(orbitingObjects[i]);
            pFragment->incrementAge();

            if (pFragment->getAge() >= pFragment->getLifespan()) {
                pFragment = nullptr;
                delete pFragment;
                orbitingObjects.erase(orbitingObjects.begin() + i);
            }

        }
    }

    for (int i = 0; i < projectiles.size(); i++) {
        applyProjectilePhysics(projectiles[i]);
    }

    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->incrementAge();

        if (projectiles[i]->getAge() >= 140) {
            projectiles[i] = nullptr;
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
        }
    }
};


