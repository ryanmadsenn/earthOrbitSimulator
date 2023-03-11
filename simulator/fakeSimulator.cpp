#include "fakeSimulator.h"

FakeSimulator::FakeSimulator() {
    initialize();
}

void FakeSimulator::initialize() {}

bool FakeSimulator::checkForCollisions() {
    for (int i = 0; i < orbitingObjects.size(); i++) {
        for (int j = 0; j < orbitingObjects.size(); j++) {
            double distance = sqrt(pow(orbitingObjects[i]->getPosition().getMetersX() - orbitingObjects[j]->getPosition().getMetersX(), 2) +
                            pow(orbitingObjects[i]->getPosition().getMetersY() - orbitingObjects[j]->getPosition().getMetersY(), 2));

            if (distance < orbitingObjects[i]->getRadius() + orbitingObjects[j]->getRadius()) {
                return true;
            }
        }
    }

    return false;
}

void FakeSimulator::handleCollision(OrbitingObject *obj1, int obj1index, OrbitingObject *obj2, int obj2index) {
    // Ordinarily, we would call the object's break methods,
    // but that is not in the scope of this test.

    // Instead, we will just remove the objects from the vector.
    delete obj1;
    obj1 = nullptr;
    orbitingObjects.erase(orbitingObjects.begin() + obj1index);

    delete obj2;
    obj2 = nullptr;
    orbitingObjects.erase(orbitingObjects.begin() + obj2index);
}

void FakeSimulator::updateObjects() {
    for (int i = 0; i < orbitingObjects.size(); i++) {
        orbitingObjects[i]->getPosition().setMetersX(100);
        orbitingObjects[i]->getPosition().setMetersY(100);
    }
}