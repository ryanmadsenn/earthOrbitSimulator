#include "../orbitingObject.h"
#include "../../projectile/projectile.h"
#include "uiInteract/uiInteract.h"

class DreamChaser : public OrbitingObject {
private:
    bool isThrusting = false;
    bool isShooting = false;
    bool clockWise = false;
    bool counterClockWise = false;
    Position shipFront;
    Projectile projectile;

public:
    DreamChaser() : OrbitingObject() {};
    DreamChaser(Position position, double dx, double dy, double aRadians, double radius);
    void accelerate() { isThrusting = true; }
    void rotateLeft() { counterClockWise = true; }
    void rotateRight() { clockWise = true; }
    void shoot() { isShooting = true; }
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) override;
    void computeShipFront();
    Position& getShipFront() { return shipFront; }
    void fireProjectile();
//    Projectile* getProjectile() { return &projectile; }

    void move(const Interface* pUI);

    void input(const Interface* pUI);
};
