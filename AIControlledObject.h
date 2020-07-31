#include "Object.h"
#include <map>
#include <queue>
class AIControlledObject : public MotionObject {
    public:
        Tile * current_tile;
        std::map<Tile*, Tile*> recalculate_distance(Tile* t);
        void update();
};