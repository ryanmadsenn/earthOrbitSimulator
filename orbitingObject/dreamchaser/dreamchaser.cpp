#include "dreamchaser.h"
/*******************************************************
 *
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 ********************************************************/
DreamChaser::DreamChaser(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Dreamchaser");
//    velocityObject.setVelocity(dx, dy);
//    directionObject.setDirection(dx, dy);
//    computeShipFront();
}

/*******************************************************
 *
 ********************************************************/
void DreamChaser::draw() {
    drawShip(position, aRadians, isThrusting);
}

void DreamChaser::rotate(bool right) {
    right ? aRadians += 0.05 : aRadians -= 0.05;
}

void DreamChaser::thrust() {
    isThrusting = true;
}

//void DreamChaser::fireProjectile()
//{
//    // Velocity of the DreamChaser need to be added to the initial velocity of the projectile.
//    double initialVelocity = 9000.0;
//    double finalVelocity = sqrt(pow(dx, 2) + pow(dy, 2)) + initialVelocity;
//
//    projectile.reset(getShipFront(), aRadians, finalVelocity);
//    projectile.draw();
//}

/*******************************************************
 *
 * @param orbitingObjects
 ********************************************************/
void DreamChaser::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method.
}