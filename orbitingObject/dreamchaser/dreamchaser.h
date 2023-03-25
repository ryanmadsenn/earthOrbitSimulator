#pragma once
#include "../orbitingObject.h"
#include "../../projectile/projectile.h"
#include "uiInteract/uiInteract.h"

class DreamChaser : public OrbitingObject {
private:
    bool isThrusting = false;
//    bool isShooting = false;
//    Position shipFront;
    Projectile projectile;

public:
    DreamChaser() : OrbitingObject() {};
    DreamChaser(Position position, double dx, double dy, double aRadians, double radius);
    void thrust();
    void stopThrust() { isThrusting = false; }
    bool getIsThrusting() { return isThrusting; }
    void rotate(bool right);
    void shoot(vector<Projectile *> * projectiles);
    Position computeShipFront();
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};
