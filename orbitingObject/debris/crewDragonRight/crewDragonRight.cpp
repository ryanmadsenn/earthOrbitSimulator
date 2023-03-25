#include "crewDragonRight.h"

CrewDragonRight::CrewDragonRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 6, "CrewDragonRight") {}

void CrewDragonRight::draw() {
    drawCrewDragonRight(position, aRadians);
}

void CrewDragonRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}