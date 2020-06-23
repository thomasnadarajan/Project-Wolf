#include "Game.h"
#include <cstdio>
#include <png.h>
Game g(0, 0, 10, 10, 0.1);
//Object random_block = Object(30,30,10,20);

void init() {
    g.m.set_props(1, 1);
    auto obj_tup = std::make_tuple(30, 30, 10, 20, 0, -1);
    auto pos_tup = std::make_tuple(0,0);
    std::vector<std::tuple<double, double, double, double, int, double>> vect;
    vect.push_back(obj_tup);
    g.m.add_chunk(vect, pos_tup);
}
void special(int key, int, int) {
    
    auto tup = g.m.get_chunk(std::make_tuple(g.p.hitbox.main_hitbox.x, g.p.hitbox.main_hitbox.y));
    std::vector<Object> objs = g.m.chunks[tup].get_objects();
    g.p.move(objs, key);
    glutPostRedisplay();
}
void all_obj_draw() {
    auto pos_tup = std::make_tuple(0,0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);     
    draw_vertices(g.p);
    auto chunk = g.m.get_chunk(pos_tup);
    std::vector<Object> objs = g.m.chunks[chunk].get_objects();
    for (auto obj : objs) {
        draw_vertices(obj);
    }
    glFlush();
}
void mouseFunc(int x, int y) {
  /*
    float direct_vect[2];
    direct_vect[0] = x- g.p.coordinates[0];
    direct_vect[1] = y - g.p.coordinates[1];
    float rot = atan2(direct_vect[0], direct_vect[1]);
    glTranslatef(-g.p.coordinates[0], -g.p.coordinates[1], 0);
    glRotatef(rot, 0, 0, 1);
    glTranslatef(g.p.coordinates[0], g.p.coordinates[1], 0);
    glutPostRedisplay();
    */
}

int main(int argc, char ** argv) {
        glutInit(&argc, argv);
        init();          
        glutCreateWindow("Project Wolf"); 
        glutInitWindowSize(800, 800);  
        glutInitWindowPosition(80, 80); 
        glutDisplayFunc(all_obj_draw);
        glutSpecialFunc(special);
        glutPassiveMotionFunc(mouseFunc);
        glutMainLoop();

   
   return 0;
}