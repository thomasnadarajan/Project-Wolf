#include "Object.h"
Object::Object(double x, double y, double width, double height): hitbox(CollisionObject({Hitbox(x,y,width,height)})) {}


bool Chunk::get_tile(int x, int y) {
    int tile_y = y / 5;
    int tile_x = x / 5;

    return tiles[tile_y][tile_x];
}

void Chunk::set_tile(int x, int y, bool truth) {
    int tile_y = y / 5;
    int tile_x = x / 5;
    
    tiles[tile_y][tile_x] = truth;
}
/*
Chunk::Chunk(std::vector<Object> all_objects_for_chunk) {
    this->objects = all_objects_for_chunk;
    for (auto obj: this->objects) {
        if (obj.terrain == true) {
            set_tile(obj.hitbox.main_hitbox.x, obj.hitbox.main_hitbox.y, true);
        }
    }
}*/
bool Object::check_collisions(std::vector<Object> * objects) {
    for (auto obj: *objects){
        if (hitbox.main_hitbox.intersects(obj.hitbox.main_hitbox) && 
        (hitbox.main_hitbox.x != obj.hitbox.main_hitbox.x 
        && hitbox.main_hitbox.y != obj.hitbox.main_hitbox.y 
            && hitbox.main_hitbox.height != obj.hitbox.main_hitbox.height 
                && hitbox.main_hitbox.width != obj.hitbox.main_hitbox.width)){
            printf("gets here collide\n");
            return true;
        }
    }
    return false;
}

bool MotionObject::check_move(int dx,int dy, std::vector<Object> * objects){
    hitbox.main_hitbox.x+=dx;
    hitbox.main_hitbox.y+=dy;
    bool moveable = check_collisions(objects);
    hitbox.main_hitbox.x-=dx;
    hitbox.main_hitbox.y-=dy;
    return !moveable;
    
}
bool MotionObject::check_velocity() {
    if (x_vel != 0 || y_vel != 0) {
        return true;
    }
    return false;
}
void MotionObject::force_move(int dx,int dy){
    hitbox.main_hitbox.x+=dx;
    hitbox.main_hitbox.y+=dy;
}

void MotionObject::move(int dx,int dy, std::vector<Object *> objects){
    std::vector<Object> updated_objs = {};
    for (auto obj : objects) {
        updated_objs.push_back(*obj);
    }
    if (check_move(dx + x_vel ,dy + y_vel,&updated_objs)){
        force_move(dx+x_vel,dy+y_vel);
        if (momentum){
            x_vel+=dx;
            y_vel+=dy;
            x_vel *= (1-friction)/100.0;
            y_vel *= (1-friction)/100.0;
        }

    }

}
double coord_to_screen(int x) {
    return x/100.0;
}
void Object::draw() {
    glBegin(GL_QUADS);
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x), coord_to_screen(hitbox.main_hitbox.y));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x + hitbox.main_hitbox.width), coord_to_screen(hitbox.main_hitbox.y ));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x + hitbox.main_hitbox.width), coord_to_screen(hitbox.main_hitbox.y + hitbox.main_hitbox.height));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x), coord_to_screen(hitbox.main_hitbox.y + hitbox.main_hitbox.height));
    glEnd();
    glFlush();
}

void MotionObject::update() {
    printf("gets to the motion update\n");
    if(check_velocity()) {
        auto coords = return_coords();
        //std::vector<Object *> objs = {};
        move(x_vel, y_vel, map_ref->get_nearby_objects(coords));
        //move(x_vel, y_vel, objs);
    }
}

void Object::update() {
    printf("gets to the normal object update \n");
}
/*
To be implemented in the future.
void Map::update_obj_current_object() {

}
*/

