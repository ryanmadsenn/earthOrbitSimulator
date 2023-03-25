#pragma once
#include "../orbitingObject.h"
#include "../../projectile/projectile.h"
//#include "uiInteract/uiInteract.h"

class DreamChaser : public OrbitingObject {
private:
    bool isThrusting = false;
    bool isAlive = true;
    Projectile projectile;

public:
    DreamChaser() : OrbitingObject() {};
    DreamChaser(Position position, double dx, double dy, double aRadians, double radius);
    void thrust();
    void stopThrust() { isThrusting = false; }
    bool getIsThrusting() const { return isThrusting; }
    bool setDead() { this->isAlive = false; }
    void rotate(bool right);
    void shoot(vector<Projectile *> * projectiles);
    Position computeShipFront();
    void draw() override;
    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};
