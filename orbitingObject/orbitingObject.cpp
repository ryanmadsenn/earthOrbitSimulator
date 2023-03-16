#include "orbitingObject/orbitingObject.h"

/*******************************************************
 *
 ********************************************************/
OrbitingObject::OrbitingObject() {};

void OrbitingObject::initialize(Position position, double dx, double dy, double aRadians, double radius, string type) {
    this->position = position;
    this->dx = dx;
    this->dy = dy;
    this->aRadians = aRadians;
    this->radius = radius;
    this->type = type;
}

/*******************************************************
 *
 * @return
 ********************************************************/
Position * OrbitingObject::getPosition() {
    return &position;
}

/*******************************************************
 *
 * @return
 ********************************************************/
double OrbitingObject::getDx() {
    return dx;
}

/*******************************************************
 *
 * @return
 ********************************************************/
double OrbitingObject::getDy() {
    return dy;
}

/*******************************************************
 *
 * @return
 ********************************************************/
double OrbitingObject::getARadians() {
    return aRadians;
}

/*******************************************************
 *
 * @return
 ********************************************************/
double OrbitingObject::getRadius() {
    return radius;
}

/*******************************************************
 *
 * @return
 ********************************************************/
string OrbitingObject::getType() {
    return type;
}

/*******************************************************
 *
 * @param position
 ********************************************************/
void OrbitingObject::setPosition(Position position) {
    this->position = position;
}

/*******************************************************
 *
 * @param dx
 *******************************************************/
void OrbitingObject::setDx(double dx) {
    this->dx = dx;
}

/*******************************************************
 *
 * @param dy
 ********************************************************/
void OrbitingObject::setDy(double dy) {
    this->dy = dy;
}

/*******************************************************
 *
 * @param aRadians
 ********************************************************/
void OrbitingObject::setARadians(double aRadians) {
    this->aRadians = aRadians;
}

/*******************************************************
 *
 * @param radius
 ********************************************************/
void OrbitingObject::setRadius(double radius) {
    this->radius = radius;
}
