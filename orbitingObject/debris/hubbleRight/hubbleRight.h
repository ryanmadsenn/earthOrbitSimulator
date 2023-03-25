#include "../debris.h"
#include "../fragment/fragment.h"

class HubbleRight : public Debris {
public:
    HubbleRight(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};