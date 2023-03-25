#include "../debris.h"
#include "../fragment/fragment.h"

class StarlinkBody : public Debris {
public:
    StarlinkBody(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};