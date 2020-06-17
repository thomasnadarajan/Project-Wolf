#include "Object.h"
#include <cstdio>
MotionObject square(0, 0, 1, 1, 0.1);
void special(int key, int, int) {
    square.move(key);
  glutPostRedisplay();
}

void draw(Object& o) {
    glBegin(GL_QUADS);
      for (int i = 0; i < 4; i++) {
          //printf("%f\n", o.vertices[i][0]);
          glVertex2f(o.vertices[i][0], o.vertices[i][1]);
      }
}
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   // Draw a Red 1x1 Square centered at origin
   draw(square);
   glEnd();
   glFlush();
}
int main(int argc, char ** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);
   glutSpecialFunc(special);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}