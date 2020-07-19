#include "Game.h"
#include <cstdio>
#include <math.h>
#include <png.h>
#include <pthread.h>
#include <map>
#define PI 3.14
Game g(0, 0, 10, 10, 0.1);
bool keyState[246];
void game_loop() {
    g.update();
}

void keyboard(int key, int, int) {
    keyState[key] = true;
    auto tup = g.m.get_chunk(std::make_tuple(g.p.hitbox.main_hitbox.x, g.p.hitbox.main_hitbox.y));
    std::vector<Object> objs = g.m.chunks[tup].get_objects();
    g.p.move(objs, key);
    glutPostRedisplay();
}
void keyboard_released(int key, int, int) {
    keyState[key] = false;
    if (!g.p.momentum) {
        g.p.x_vel = 0;
        g.p.y_vel = 0;
    }
}
void mainLoop() {
    g.draw();
    //glutPostRedisplay();
}
void mouseFunc(int x, int y) {
    /*
    int direct_vect[2];
    direct_vect[0] = x - g.p.hitbox.main_hitbox.x;
    direct_vect[1] = y - g.p.hitbox.main_hitbox.y;
    glTranslatef(-g.p.hitbox.main_hitbox.x, -g.p.hitbox.main_hitbox.y, 0);
    
    double rot = atan2(direct_vect[0], direct_vect[1]);
    if (rot < 0) {
        rot += (2 * PI);
    }
    glRotatef(rot, 0, 0, 1);
    glTranslatef(g.p.hitbox.main_hitbox.x, g.p.hitbox.main_hitbox.y, 0);
    glutPostRedisplay();
    */
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    g.init();
    glutCreateWindow("Project Wolf"); 
    glutInitWindowSize(800, 800);  
    glutInitWindowPosition(80, 80); 
    glutDisplayFunc(mainLoop);
    glutSpecialFunc(keyboard);
    glutSpecialUpFunc(keyboard_released);
    glutPassiveMotionFunc(mouseFunc);
    glutIdleFunc(game_loop);
    glutMainLoop();
    
   return 0;
}