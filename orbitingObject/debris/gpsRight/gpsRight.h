#include "../debris.h"
#include "../fragment/fragment.h"

class GPSRight : public Debris {
public:
    GPSRight(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};