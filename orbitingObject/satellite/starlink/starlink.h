#include "orbitingObject/satellite/satellite.h"

class Starlink : public Satellite {
public:
    Starlink(Position position, double dx, double dy, double aRadins, double radius);
    Starlink(double x, double y) : Satellite(x, y) {};
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};