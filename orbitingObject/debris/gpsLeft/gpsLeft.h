#include "../debris.h"
#include "../fragment/fragment.h"

class GPSLeft : public Debris {
public:
    GPSLeft(Position position, double dx, double dy, double aRadians);

    virtual void draw() override;

    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};