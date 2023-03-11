#include "satellite.h"

class GPS : public Satellite {
public:
    GPS(Position position, double dx, double dy, double aRadins, double radius);
    virtual void draw() const;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) const;
};