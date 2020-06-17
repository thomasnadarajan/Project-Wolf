#include <math.h>
#include <GL/glut.h>
#include <cstdio>
class Object {
    public:
        double vertices[4][2];
        int coordinates[2];
    public:
        Object(double x, double y, double width, double height) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    if (j == 0) {
                        if (i < 2) {
                            vertices[i][j] = x - (width/2.0);
                        }
                        else {
                            vertices[i][j] = x + (width/2.0);
                        }
                    }
                    else {
                        if (i % 2 == 0) {
                            vertices[i][j] = y - (width/2.0);
                        }
                        else {
                            vertices[i][j] = y + (width/2.0);
                        }
                    }
                }
            }
        }
};
class MotionObject: public Object {
    private:
        double movement_iter;
    public:
        MotionObject(double x, double y, double width, double height, double m) : Object(x, y, width, height) {
            movement_iter = m;
        }
        void move(int key) {
            if (key == GLUT_KEY_LEFT) {
                for (int i = 0; i < 4; i++) {
                    vertices[i][0] -= movement_iter;
                }
            }
            else if (key ==GLUT_KEY_RIGHT) {
                for (int i = 0; i < 4; i++) {
                    vertices[i][0] += movement_iter;
                }
            }
            else if (key == GLUT_KEY_UP) {
                for (int i = 0; i < 4; i++) {
                    vertices[i][1] += movement_iter;
                }
            }
            else if (key == GLUT_KEY_DOWN) {
                for (int i = 0; i < 4; i++) {
                    vertices[i][1] -= movement_iter;
                }
            }
        }
    
};