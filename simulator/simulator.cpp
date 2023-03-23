#include "simulator.h"

/*******************************************************
 *
 *******************************************************/
Simulator::Simulator(const Position ptUpperRight) {
    initialize();
}

/*******************************************************
 *
 *******************************************************/
void Simulator::initialize()
{
    /* create 200 stars */
    for (int i = 0; i < 200; i++)
        stars.push_back(Star(Position(random(-99999999.0, 99999999.0), random(-99999999.0, 99999999.0)), random(0, 224)));

    /* create earth */
    earth = Earth();

    /* create 6 gps satellites */
    orbitingObjects.push_back(new GPS(Position( 0.0,          26560000.0  ), -3880.0,  0.0,      0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( 23001634.72,  13280000.0  ), -1940.0,  3360.18,  0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( 23001634.72,  -13280000.0 ),  1940.0,  3360.18,  0.0, 12.0)); 
    orbitingObjects.push_back(new GPS(Position( 0.0,          -26560000.0 ),  3880.0,  0.0,      0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( -23001634.72, -13280000.0 ),  1940.0,  -3360.18, 0.0, 12.0));
    orbitingObjects.push_back(new GPS(Position( -23001634.72, 13280000.0  ), -1940.0,  -3360.18, 0.0, 12.0));
     
    /* create 5 other orbiting objects */
    orbitingObjects.push_back(new Sputnik      (Position(-36515095.13, 21082000.0),  2050.0,  2684.68, 0.0, 4.0));
    orbitingObjects.push_back(new Hubble       (Position(0.0,          42164000.0),  3100.0,  0.0,     0.0, 10.0));
    orbitingObjects.push_back(new Starlink     (Position(0.0,         -13020000.0),  5800.0,  0.0,     0.0, 6.0));
    orbitingObjects.push_back(new CrewDragon   (Position(0.0,           8000000.0),  -7900.0, 0.0,     0.0, 7.0));
    orbitingObjects.push_back(new DreamChaser  (Position(-45000000.0,  45000000.0),  0.0,     -2000,   0.0, 10.0));
};  

/*******************************************************
 *
 *******************************************************/
void Simulator::update() {
//    handleInput(pUI);
    checkForCollisions();
    updateObjects();
}

/*******************************************************
 *
 * @param pUI
 *******************************************************/
void Simulator::handleInput(const Interface *pUI) {
    dreamChaser.input(pUI);
}

/*******************************************************
 *
 * @return
 *******************************************************/
bool Simulator::checkForCollisions() {
//    for (int i = 0; i < orbitingObjects.size(); i++) {
//        for (int j = 0; j < orbitingObjects.size(); j++) {
//            if (orbitingObjects[i].isAlive() && orbitingObjects[j].isAlive())
//                distance = sqrt(pow(orbitingObjects[i]->getX() - orbitingObjects[j]->getX(), 2) +
//                            pow(orbitingObjects[i]->getY() - orbitingObjects[j]->getY(), 2));
//
//            if (distance < orbitingObjects[i]->getRadius() + orbitingObjects[j]->getRadius()) {
//                handleCollision(orbitingObjects[i], i, orbitingObjects[j], j);
//            }
//        }
//    }
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
//    obj1->break(orbitingObjects);
//    obj2->break(orbitingObjects);
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
//
//    for (int i = 0; i < projectiles.size(); i++) {
//        projectiles[i].draw();
//    }
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
    }
};


