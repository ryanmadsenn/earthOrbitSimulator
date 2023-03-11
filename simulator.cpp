#include "simulator.h"

Simulator::Simulator() {
    for (int i = 0; i < 200; i++) {
        stars.push_back(Star());
    }

    earth = Earth();

    for (int i = 0; i < 6; i++) {
        orbitingObjects.push_back(new GPS());
    }

    orbitingObjects.push_back(new Sputnik());
    orbitingObjects.push_back(new Hubble());
    orbitingObjects.push_back(new Starlink());
    orbitingObjects.push_back(new CrewDragon());
    orbitingObjects.push_back(new DreamChaser());
}

void Simulator::update() {
    handleInput();
    checkForCollisions();
    updateObjects();
}

void Simulator::handleInput() {
    if (pUI->isSpace())
        projectiles.push_back(Projectile(dreamChaser.getDX(), dreamChaser.getDY()));
    else if (pUI->isLeft())
        dreamChaser.rotateLeft();
    else if (pUI->isRight())
        dreamChaser.rotateRight();
    else if (pUI->isDown())
        dreamChaser.accelerate();
}

void Simulator::checkForCollisions() {
    for (int i = 0; i < orbitingObjects.size(); i++) {
        for (int j = 0; j < orbitingObjects.size(); j++) {
            distance = sqrt(pow(orbitingObjects[i]->getX() - orbitingObjects[j]->getX(), 2) +
                            pow(orbitingObjects[i]->getY() - orbitingObjects[j]->getY(), 2));

            if (distance < orbitingObjects[i]->getRadius() + orbitingObjects[j]->getRadius()) {
                handleCollision(orbitingObjects[i], i, orbitingObjects[j], j);
            }
        }
    }
}

void Simulator::handleCollision(OrbitingObject *pObj1, int obj1index, OrbitingObject *pObj2, int obj2index) {
    obj1->break(orbitingObjects);
    obj2->break(orbitingObjects);


}

void Simulator::addOrbitingObject(int *pObj) {
    orbitingObjects.push_back(pObj);
}

vector<OrbitingObject> Simulator::getOrbitingObjects()
{
    return orbitingObjects;
}

void Simulator::clearOrbitingObjects() {
    orbitingObjects.clear();
}

void Simulator::draw() {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw();
    }

    earth.draw();

    for (int i = 0; i < orbitingObjects.size(); i++) {
        orbitingObjects[i]->draw();
    }

    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i].draw();
    }
}


