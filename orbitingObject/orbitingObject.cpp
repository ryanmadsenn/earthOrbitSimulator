#include "../orbitingObject/orbitingObject.h"

/*******************************************************
 * Description: Constructor.
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
 * Description: returns the position of the object.
 * @return Position
 ********************************************************/
Position * OrbitingObject::getPosition() {
    return &position;
}

/*******************************************************
 * Description: returns the x velocity of the object.
 * @return double
 ********************************************************/
double OrbitingObject::getDx() {
    return dx;
}

/*******************************************************
 * Description: returns the y velocity of the object.
 * @return double
 ********************************************************/
double OrbitingObject::getDy() {
    return dy;
}

/*******************************************************
 * Description: returns the angle of the object.
 * @return double
 ********************************************************/
double OrbitingObject::getARadians() {
    return aRadians;
}

/*******************************************************
 * Description: returns the radius of the object.
 * @return double
 ********************************************************/
double OrbitingObject::getRadius() {
    return radius;
}

/*******************************************************
 * Description: returns the type of the object.
 * @return string
 ********************************************************/
string OrbitingObject::getType() {
    return type;
}

/*******************************************************
 * Description: sets the position of the object.
 * @param dx
 *******************************************************/
void OrbitingObject::setDx(double dx) {
    this->dx = dx;
}

/*******************************************************
 * Description: sets the y velocity of the object.
 * @param dy
 ********************************************************/
void OrbitingObject::setDy(double dy) {
    this->dy = dy;
}

/*******************************************************
 * Description: sets the angle of the object.
 * @param aRadians
 ********************************************************/
void OrbitingObject::setARadians(double aRadians) {
    this->aRadians = aRadians;
}

/*******************************************************
 * Description: sets the radius of the object.
 * @param radius
 ********************************************************/
void OrbitingObject::setRadius(double radius) {
    this->radius = radius;
}
