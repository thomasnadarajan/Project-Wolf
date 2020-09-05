#include "Object.h"
Object::Object(double x, double y, double width, double height): hitbox(CollisionObject({Hitbox(x,y,width,height)})) {}
Tile::Tile(int x, int y) {
    this->x = x;
    this->y = y;
}
Chunk::Chunk() {
    for (int i = 0; i < 1000; i+=25) {
        for (int j = 0; j < 1000; j+=25) {
            tiles.push_back(Tile(i, j));
        }
    }
    for (int i = 0; i < 1600; i++) {
        if (tiles[i].x == 0 || tiles[i].x == 1000 - 25 || tiles[i].y == 1000 - 25 || tiles[i].y == 0) {
            if (tiles[i].x == 0) {
                for (int j = 0; j < 1600; j++) {
                    if (tiles[j].x == 25) {
                        tiles[i].edges.push_back(&tiles[j]);
                    }
                }
            }
            else if (tiles[i].x == 1000 - 25) {
                for (int j = 0; j < 1600; j++) {
                    if (tiles[j].x == 1000 - 50) {
                        tiles[i].edges.push_back(&tiles[j]);
                    }
                }
            }
            if (tiles[i].y == 0) {
                for (int j = 0; j < 1600; j++) {
                    if (tiles[j].y == 25) {
                        tiles[i].edges.push_back(&tiles[j]);
                    }
                }
            }
            else if (tiles[i].y == 1000 - 25) {
                for (int j = 0; j < 1600; j++) {
                    if (tiles[j].y == 1000 - 50) {
                        tiles[i].edges.push_back(&tiles[j]);
                    }
                }
            }
        }
        else {
            for (int j = 0; j < 1600; j++) {
                if (tiles[j].x == tiles[i].x - 25 && (tiles[j].y == tiles[i].y || tiles[j].y == tiles[i].y - 25 || tiles[j].y == tiles[i].y + 25)) {
                    tiles[i].edges.push_back(&tiles[j]);
                }
                else if (tiles[j].x == tiles[i].x + 25 && (tiles[j].y == tiles[i].y || tiles[j].y == tiles[i].y - 25 || tiles[j].y == tiles[i].y + 25)) {
                    tiles[i].edges.push_back(&tiles[j]);
                }
                else if (tiles[j].x == tiles[i].x && (tiles[j].y == tiles[i].y - 25 || tiles[j].y == tiles[i].y + 25)) {
                    tiles[i].edges.push_back(&tiles[j]);
                }
            }
        }
    }
}
bool Object::check_collisions(std::vector<Object> objects) {
    for (auto obj: objects){
        if (hitbox.main_hitbox.intersects(obj.hitbox.main_hitbox) && (&hitbox != &obj.hitbox)){
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

void MotionObject::move(int dx,int dy, std::vector<Object> objects){
    if (check_move(dx + x_vel ,dy + y_vel,objects)){
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
    if(check_velocity()) {
        auto coords = return_coords();
        move(x_vel, y_vel, map_ref->get_nearby_objects(coords));
    }
}

void Object::update() {
    printf("this is called42\n");
}

