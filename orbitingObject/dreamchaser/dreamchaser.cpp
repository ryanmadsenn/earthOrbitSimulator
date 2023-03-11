#include "dreamchaser.h"

DreamChaser::DreamChaser(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "DreamChaser");
}

void DreamChaser::thrust() {
    isThrusting = true;
    // TODO: Implement this method.
}

void DreamChaser::shoot() {
    // TODO: Implement this method.
}

void DreamChaser::draw() const {
    drawShip(position, aRadians, isThrusting);
}

void DreamChaser::smash(vector<OrbitingObject *> orbitingObjects) const {
    // TODO: Implement this method.
}