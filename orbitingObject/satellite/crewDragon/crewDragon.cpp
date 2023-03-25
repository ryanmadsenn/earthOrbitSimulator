#include "crewDragon.h"

/*******************************************************
 *
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 *******************************************************/
CrewDragon::CrewDragon(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "CrewDragon");
}

/*******************************************************
 *
 *******************************************************/
void CrewDragon::draw() {
    drawCrewDragon(position, aRadians);
}

/*******************************************************
 *
 * @param orbitingObjects
 *******************************************************/
void CrewDragon::smash(vector<OrbitingObject *> * orbitingObjects) {
    orbitingObjects->push_back(new CrewDragonCenter(position, dx, dy, aRadians));
    orbitingObjects->push_back(new CrewDragonLeft(position, dx, dy, aRadians));
    orbitingObjects->push_back(new CrewDragonRight(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
}
