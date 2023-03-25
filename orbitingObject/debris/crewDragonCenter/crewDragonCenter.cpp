#include "crewDragonCenter.h"
/**********************************************************************
 * Description: Constructor for CrewDragonCenter.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 ************************************************************************/
CrewDragonCenter::CrewDragonCenter(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonCenter") {}

/**********************************************************************
 * Description: Draws the CrewDragonCenter.
 ************************************************************************/
void CrewDragonCenter::draw() {
    drawCrewDragonLeft(position, aRadians);
}

/**********************************************************************
 * Description: Smashes the CrewDragonCenter into fragments.
 * @param orbitingObjects
 ************************************************************************/
void CrewDragonCenter::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 4; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}