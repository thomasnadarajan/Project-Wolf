#ifndef OBJ
#define OBJ
#include "Object.h"
#endif
#include <map>
#include <queue>
class AIControlledObject : public MotionObject {
    public:
        AIControlledObject(double x, double y, double width, double height, Map * m): MotionObject(x, y, width, height,m) {}
        std::map<Tile*, Tile*> recalculate_distance(Tile* t);
        virtual void update();
};