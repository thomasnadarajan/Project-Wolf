#include "CollisionObject.h"
/*
Comments:
Collision between 2 objects is "done" for the most part but not tested at all.
So it probably has a mistake.
*/
Hitbox::Hitbox (int ox, int oy, int oh, int ow) {
    x = ox;
    y = oy; 
    width = oh;
    height = ow;
}
Hitbox::Hitbox() {
}
bool Hitbox::intersects(Hitbox box){ 
    return !(x> box.x+box.width || box.x > width+x || y > box.height+box.y || box.y > height+y);
}


CollisionObject::CollisionObject(std::vector<Hitbox> hbs) {
        Hitbox temp_h = hbs[0];
        int x = temp_h.x;
        int y = temp_h.y;
        int width = temp_h.width;
        int height = temp_h.height;
        hitboxes = {};
        
        for (auto hb: hbs){
            num_hitboxes++;
            if (x > hb.x){
                x = hb.x;
            }
            if (width < hb.width){
                x = hb.width;
            }
            if (y > hb.y){
                y = hb.y;
            }
            if (height < hb.height){
                height = hb.height;
            }
            hitboxes.push_back(hb);
        }
        main_hitbox = Hitbox(x,y,width,height);
}

bool CollisionObject::intersects (CollisionObject box){
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