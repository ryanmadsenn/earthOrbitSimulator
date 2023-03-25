#include "crewDragonLeft.h"

/*******************************************************
 * Description: Constructor for CrewDragonLeft.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
CrewDragonLeft::CrewDragonLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonLeft") {}

/*******************************************************
 * Description: Draws the CrewDragonLeft.
 *******************************************************/
void CrewDragonLeft::draw() {
    drawCrewDragonLeft(position, aRadians);
}

/*******************************************************
 * Description: Breaks the CrewDragonLeft into fragments.
 * @param orbitingObjects
 *******************************************************/
void CrewDragonLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}