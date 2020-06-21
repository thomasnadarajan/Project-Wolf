#include "Object.h"

<<<<<<< HEAD
Object::Object(double x, double y, double width, double height): hitbox(CollisionObject({Hitbox(x,y,width,height)})) {}
=======
Object::Object(double x, double y, double width, double height): hitbox(CollisionObject({Hitbox(x,y,width,height)})){
}
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b

bool Object::check_collisions(std::vector<Object> objects) {
    for (auto obj: objects){
        if (hitbox.main_hitbox.intersects(obj.hitbox.main_hitbox)){
            return true;
<<<<<<< HEAD
=======
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
    if (check_move(dx + x_vel ,dy + y_vel,objects)){
        force_move(dx+x_vel,dy+y_vel);
        
        if (momentum){
            x_vel+=dx;
            y_vel+=dy;
            x_vel *= (1-friction)/100.0;
            y_vel *= (1-friction)/100.0;
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b
        }

    }
<<<<<<< HEAD
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
=======

}



>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b
