#include "orbitingObject/orbitingObject.h"

OrbitingObject::OrbitingObject() {};

void OrbitingObject::initialize(Position position, double dx, double dy, double aRadians, double radius, string type) {
    this->position = position;
    this->dx = dx;
    this->dy = dy;
    this->aRadians = aRadians;
    this->radius = radius;
    this->type = type;
}

Position * OrbitingObject::getPosition() {
    return &position;
}

double OrbitingObject::getDx() {
    return dx;
}

double OrbitingObject::getDy() {
    return dy;
}

double OrbitingObject::getARadians() {
    return aRadians;
}

double OrbitingObject::getRadius() {
    return radius;
}

string OrbitingObject::getType() {
    return type;
}

void OrbitingObject::setPosition(Position position) {
    this->position = position;
}

void OrbitingObject::setDx(double dx) {
    this->dx = dx;
}

void OrbitingObject::setDy(double dy) {
    this->dy = dy;
}

void OrbitingObject::setARadians(double aRadians) {
    this->aRadians = aRadians;
}

void OrbitingObject::setRadius(double radius) {
    this->radius = radius;
}
