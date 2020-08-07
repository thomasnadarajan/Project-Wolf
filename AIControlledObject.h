#include "Object.h"
#include <map>
#include <queue>
class AIControlledObject : public MotionObject {
    public:
        AIControlledObject(double x, double y, double width, double height): MotionObject();
        std::map<Tile*, Tile*> recalculate_distance(Tile* t);
        void update();
};