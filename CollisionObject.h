#include <iostream>
#include <vector>
/*
Comments:
Collision between 2 objects is "done" for the most part but not tested at all.
So it probably has a mistake.
*/
class Hitbox {
    public:
        int x;
        int y;
        int width;
        int height;
        Hitbox (int ox, int oy, int oh, int ow);
        Hitbox ();
        bool intersects(Hitbox box);
};
class CollisionObject{
    public:
        int num_hitboxes;
        std::vector<Hitbox> hitboxes;
        Hitbox main_hitbox; // a hitbox that surrounds all the other hitboxes
        CollisionObject(std::vector<Hitbox> hbs);
        bool intersects (CollisionObject box);
};
