#include "orbitingObject/satellite/satellite.h"

class Hubble : public Satellite {
public:
    Hubble(Position position, double dx, double dy, double aRadins, double radius);
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};
