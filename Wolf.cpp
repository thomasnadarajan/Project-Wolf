#include "Game.h"
#include <cstdio>
#include <math.h>
#include <png.h>
#include <pthread.h>
#include <map>
#define PI 3.14
Game g(0, 0, 10, 10);

void timer( int extra )
{
    g.update();
    glutPostRedisplay();
    glutTimerFunc( 16, timer, 0 );
}

void game_loop() {
    
}

void keyboard(int key, int, int) {
    g.p.keyState[key] = true;
    auto tup = g.m.get_chunk(std::make_tuple(g.p.hitbox.main_hitbox.x, g.p.hitbox.main_hitbox.y));
    std::vector<Object> objs = g.m.chunks[tup].get_objects();
    g.p.move(objs, key);
    g.update();
}
void keyboard_released(int key, int, int) {
    printf("released: %d\n", g.p.hitbox.main_hitbox.y);
    g.p.keyState[key] = false;
    if (g.p.momentum == false) {
        if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {
            g.p.y_vel = 0;
        }
        else {
            g.p.x_vel = 0;
        }
    }
    printf("released2: %d\n", g.p.hitbox.main_hitbox.y);
}
void mainLoop() {
    g.draw();
    //glutPostRedisplay();
}
void mouseFunc(int x, int y) {
    int direct_vect[2];
    direct_vect[0] = x - g.p.hitbox.main_hitbox.x;
    direct_vect[1] = y - g.p.hitbox.main_hitbox.y;
    
    double rot = atan2(direct_vect[0], direct_vect[1]);
    if (rot < 0) {
        rot += (2 * PI);
    }
    g.p.theta = rot;
    g.update();
    printf("%f\n", g.p.theta);    
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    g.init();
    //printf("Momentum: %d\n", g.p.momentum);
    glutSetKeyRepeat(0);
    glutCreateWindow("Project Wolf"); 
    glutInitWindowSize(1000, 1000);  
    glutInitWindowPosition(80, 80); 
    glutSpecialFunc(keyboard);
    glutSpecialUpFunc(keyboard_released);
    glutPassiveMotionFunc(mouseFunc);
    glutDisplayFunc(mainLoop);
    glutTimerFunc( 0, timer, 0 );
    glutIdleFunc(game_loop);
    glutMainLoop();
   return 0;
}