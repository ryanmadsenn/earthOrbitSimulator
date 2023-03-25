#include "../debris.h"
#include "../fragment/fragment.h"

class GPSLeft : public Debris {
public:
    GPSLeft(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};