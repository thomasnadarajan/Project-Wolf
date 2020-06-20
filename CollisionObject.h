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
    
        bool intersects(Hitbox box);
        Hitbox (int ox, int oy, int oh, int ow);
        
};
class CollisionObject{
    
    public:
        std::vector<Hitbox> hitboxes;
        int num_hitboxes;
        Hitbox main_hitbox; // a hitbox that surrounds all the other hitboxes

        CollisionObject(std::vector<Hitbox> hbs);


        bool intersects (CollisionObject box);
}

};