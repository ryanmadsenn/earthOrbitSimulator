#include "../debris.h"
#include "../fragment/fragment.h"

class GPSCenter : public Debris {
public:
    GPSCenter(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};