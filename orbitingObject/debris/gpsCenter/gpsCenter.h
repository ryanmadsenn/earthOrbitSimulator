#include "../debris.h"
#include "../fragment/fragment.h"

class GPSCenter : public Debris {
public:
    GPSCenter(Position position, double dx, double dy, double aRadians);

    virtual void draw() override;

    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};