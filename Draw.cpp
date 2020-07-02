#include "Draw.h"

double coord_to_screen(int x) {
    return x/100.0;
}

void draw_vertices(Object& obj) {
    // Draw vertices based on the current value of theta.
    glBegin(GL_QUADS);
    if ((int) obj.theta % 90 == 0) {
        glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x), coord_to_screen(obj.hitbox.main_hitbox.y));
        glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width), coord_to_screen(obj.hitbox.main_hitbox.y ));
        glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x + obj.hitbox.main_hitbox.width), coord_to_screen(obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height));
        glVertex2f(coord_to_screen(obj.hitbox.main_hitbox.x), coord_to_screen(obj.hitbox.main_hitbox.y + obj.hitbox.main_hitbox.height));
    }
    else {
        
    }
    glEnd();
    glFlush();
}