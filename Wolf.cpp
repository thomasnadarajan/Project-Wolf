#include "Game.h"
#include <cstdio>
#include <png.h>
Game g(0, 0, 1, 1, 0.1);
void special(int key, int, int) {
    g.p.move(key);
  glutPostRedisplay();
}
void mouseFunc(int x, int y) {
  
    float direct_vect[2];
    direct_vect[0] = g.p.coordinates[0] - x;
    direct_vect[1] = g.p.coordinates[1] - y;
    float rot = atan2(-direct_vect[1], direct_vect[0]);
    glTranslatef(-g.p.coordinates[0], -g.p.coordinates[1], 0);
    glRotatef(rot, 0, 0, 1);
    glTranslatef(g.p.coordinates[0], g.p.coordinates[1], 0);
    glutPostRedisplay();
    
}

void draw(Object& o) {
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++) {
        glVertex2f(o.vertices[i][0], o.vertices[i][1]);
    }
}
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
   draw(g.p);
   glEnd();
   glFlush();
}
int main(int argc, char ** argv) {
    glutInit(&argc, argv);          
   glutCreateWindow("Project Wolf"); 
   glutInitWindowSize(320, 320);  
   glutInitWindowPosition(50, 50); 
   glutDisplayFunc(display);
   glutSpecialFunc(special);
   glutPassiveMotionFunc(mouseFunc);
   glutMainLoop();
   return 0;
}