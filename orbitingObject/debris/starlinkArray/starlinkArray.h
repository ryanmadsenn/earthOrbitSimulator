#include "../debris.h"
#include "../fragment/fragment.h"

class StarlinkArray : public Debris {
public:
    StarlinkArray(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};