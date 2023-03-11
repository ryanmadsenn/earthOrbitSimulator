#include "satellite.h"

class Starlink : public Satellite {
public:
    Starlink(Position position, double dx, double dy, double aRadins, double radius);
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};