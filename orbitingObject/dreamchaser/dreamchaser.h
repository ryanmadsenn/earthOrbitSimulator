#include "../orbitingObject.h"

class DreamChaser : public OrbitingObject {
private:
    bool isThrusting = false;

public:
    DreamChaser() : OrbitingObject() {};
    DreamChaser(Position position, double dx, double dy, double aRadins, double radius);
    void thrust();
    void shoot();
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) override;
    //virtual void smash(vector<OrbitingObject *> orbitingObjects) override;
};
