#include "../debris.h"
#include "../fragment/fragment.h"

class HubbleComputer : public Debris {
public:
    HubbleComputer(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};

