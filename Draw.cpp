#include "Draw.h"

double coord_to_screen(int x) {
    return x/100.0;
}

void draw_vertices(Object& obj) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);       
    glBegin(GL_QUADS);
    glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x), coord_to_screen(obj.hitbox.main_hitbox.y));
    glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width), coord_to_screen(obj.hitbox.main_hitbox.y ));
    glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width), coord_to_screen(obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height));
    glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x), coord_to_screen(obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height));
    
    glEnd();
    glFlush();
}

