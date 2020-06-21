#include "Draw.h"

void draw_vertices(Object& obj) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);       
    glBegin(GL_QUADS);
    glVertex2f(obj.hitbox.main_hitbox.x - obj.hitbox.main_hitbox.width, obj.hitbox.main_hitbox.y - obj.hitbox.main_hitbox.height);
    glVertex2f(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width, obj.hitbox.main_hitbox.y - obj.hitbox.main_hitbox.height);
    glVertex2f(obj.hitbox.main_hitbox.x - obj.hitbox.main_hitbox.width, obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height);
    glVertex2f(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width, obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height);
    glEnd();
}

