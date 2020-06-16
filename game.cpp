#include <GL/glut.h>
float vertices[4][2];
void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: 
        for (int i =0; i < 4; i ++) {
            vertices[i][0] -= 0.1f;
        }
        break;
    case GLUT_KEY_RIGHT: 
        for (int i =0; i < 4; i ++) {
            vertices[i][0] += 0.1f;
        }
        break;
    case GLUT_KEY_UP: 
        for (int i =0; i < 4; i ++) {
            vertices[i][1] += 0.1f;
        }
        break;
    case GLUT_KEY_DOWN: 
        for (int i =0; i < 4; i ++) {
            vertices[i][1] -= 0.1f;
        }
        break;
    default: return;
  }
  glutPostRedisplay();
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      for (int i = 0; i < 4; i++) {
          glVertex2f(vertices[i][0], vertices[i][1]);
      }
   glEnd();
 
   glFlush();
}
int main(int argc, char ** argv) {
    vertices[0][0] = -0.5f; 
    vertices[0][1] = -0.5f;
    vertices[1][0] = -0.5f;
    vertices[1][1] = 0.5f;
    vertices[2][0] = 0.5f;
    vertices[2][1] = -0.5f;
    vertices[3][0] = 0.5f;
    vertices[3][1] = 0.5f;
    glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);
   glutSpecialFunc(special);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}