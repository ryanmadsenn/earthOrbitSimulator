#include "crewDragonCenter.h"

CrewDragonCenter::CrewDragonCenter(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonCenter") {}

void CrewDragonCenter::draw() {
    drawCrewDragonLeft(position, aRadians);
}

void CrewDragonCenter::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 4; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}