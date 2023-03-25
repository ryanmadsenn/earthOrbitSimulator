#include "crewDragonLeft.h"

CrewDragonLeft::CrewDragonLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonLeft") {}

void CrewDragonLeft::draw() {
    drawCrewDragonLeft(position, aRadians);
}

void CrewDragonLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}