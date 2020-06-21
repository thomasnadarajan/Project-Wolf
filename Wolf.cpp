#include "Game.h"
#include <cstdio>
#include <png.h>
Game g(0, 0, 1, 1, 0.1);

void special(int key, int, int) {
    g.p.move(key);
  glutPostRedisplay();
}
void all_obj_draw() {
    draw_vertices(g.p);
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
   glutCreateWindow("Project Wolf"); 
   glutInitWindowSize(800, 800);  
   glutInitWindowPosition(80, 80); 
   glutDisplayFunc(all_obj_draw);
   glutSpecialFunc(special);
   glutPassiveMotionFunc(mouseFunc);
   glutMainLoop();

   
   return 0;
}