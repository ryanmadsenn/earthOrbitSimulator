#include "orbitingObject/satellite/satellite.h"

class CrewDragon : public Satellite {
public:
    CrewDragon(Position position, double dx, double dy, double aRadins, double radius);
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};
