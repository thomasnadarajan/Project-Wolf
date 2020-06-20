#include <iostream>
#include <vector>
#include "CollisionObject.h"
/*
Comments:
Collision between 2 objects is "done" for the most part but not tested at all.
So it probably has a mistake.
*/
Hitbox::Hitbox (int ox, int oy, int oh, int ow) {
    x = ox;
    y = oy; 
    dx = oh;
    dy = ow;
}
Hitbox::Hitbox() {
}
CollisionObject(std::vector<Hitbox> hbs) {
        Hitbox temp_h = hbs[0];
        int x = temp_h.x;
        int y = temp_h.y;
        int dx = temp_h.dx;
        int dy = temp_h.dy;
        
        for (auto hb: hbs){
            num_hitboxes++;
            if (x > hb.x){
                x = hb.x;
            }
            if (dx < hb.dx){
                x = hb.dx;
            }
            if (y > hb.y){
                y = hb.y;
            }
            if (dy < hb.dy){
                dy = hb.dy;
            }
            hitboxes.push_back(hb);
        }
        main_hitbox = Hitbox(x,y,dx,dy);
}
bool intersects(Hitbox box){ 
    return !(x> box.dx || box.x > dx || y > box.dy || box.y > dy);
}

bool intersects (CollisionObject box){
    if (!main_hitbox.intersects(box.main_hitbox)){
        return false;
    }
    for (auto hit_a : box.hitboxes){
        for (auto hit_b : hitboxes){
            if (hit_a.intersects(hit_b)){
                return true;
            }
        }
    }
    return false;
}