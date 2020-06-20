#include <iostream>
#include <vector>
#include "Object.h"
/*
Comments:
Collision between 2 objects is "done" for the most part but not tested at all.
So it probably has a mistake.
*/


class Hitbox {
    public:
        int x;
        int y;
        int dx;
        int dy;
        Hitbox (int ox, int oy, int oh, int ow);
        bool intersects(Hitbox box);
};
class CollisionObject{
    public:
        int num_hitboxes;
        CollisionObject(std::vector<Hitbox> hbs);
        std::vector<Hitbox> hitboxes;
        Hitbox main_hitbox; // a hitbox that surrounds all the other hitboxes
        bool intersects (CollisionObject box);
};
