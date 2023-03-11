#include "crewDragon.h"

CrewDragon::CrewDragon(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "CrewDragon");
}

void CrewDragon::draw() {
    drawCrewDragon(position, aRadians);
}

void CrewDragon::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method
}
