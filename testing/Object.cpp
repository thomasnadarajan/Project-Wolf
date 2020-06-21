#include "Object.h"

Object::Object(double x, double y, double width, double height): hitbox(CollisionObject({Hitbox(x,y,width,height)})){}

bool Object::check_collisions(std::vector<Object> objects) {
    for (auto obj: objects){
        if (hitbox.main_hitbox.intersects(obj.hitbox.main_hitbox)){
            return true;
        }
    }
    return false;

}

bool MotionObject::check_move(int dx,int dy, std::vector<Object> objects){
    hitbox.main_hitbox.x+=dx;
    hitbox.main_hitbox.y+=dy;
    bool moveable = check_collisions(objects);
    hitbox.main_hitbox.x-=dx;
    hitbox.main_hitbox.y-=dy;
    return !moveable;
    
}

void MotionObject::force_move(int dx,int dy){
    hitbox.main_hitbox.x+=dx;
    hitbox.main_hitbox.y+=dy;
}

void MotionObject::move(int dx,int dy, std::vector<Object> objects){
    if (check_move(dx ,dy ,objects)){
        force_move(dx+x_move,dy+y_move);
    }
    
}


