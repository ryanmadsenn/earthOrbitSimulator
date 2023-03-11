#include "../orbitingObject.h"

class DreamChaser : public OrbitingObject {
private:
    bool isThrusting = false;

public:
    DreamChaser(Position position, double dx, double dy, double aRadins, double radius);
    void thrust();
    void shoot();
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};
