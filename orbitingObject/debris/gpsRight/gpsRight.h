#include "../debris.h"
#include "../fragment/fragment.h"

class GPSRight : public Debris {
public:
    GPSRight(Position position, double dx, double dy, double aRadians);

    virtual void draw() override;

    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};