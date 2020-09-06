#ifndef OBJ
#define OBJ
#include "Object.h"
#endif
#include <map>
#include <queue>
class AIControlledObject : public MotionObject {
    public:

        AIControlledObject(double x, double y, double width, double height, Map * m): MotionObject(x, y, width, height,m) {
            this->x_vel = -1;
        }
};