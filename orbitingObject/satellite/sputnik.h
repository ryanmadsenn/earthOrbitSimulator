#include "satellite.h"

class Sputnik : public Satellite {

public:
    Sputnik(Position position, double dx, double dy, double aRadians, double radius);
    virtual void draw(ogstream gout);
    virtual void smash(vector<OrbitingObject*> orbitingObjects);
};