#include "crewDragonRight.h"

/*******************************************************
 * Description: Constructor for CrewDragonRight.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
CrewDragonRight::CrewDragonRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonRight") {}

/*******************************************************
 * Description: Draws the CrewDragonRight.
 *******************************************************/
void CrewDragonRight::draw() {
    drawCrewDragonRight(position, aRadians);
}

/*******************************************************
 * Description: Breaks the CrewDragonRight into fragments.
 * @param orbitingObjects
 *******************************************************/
void CrewDragonRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}