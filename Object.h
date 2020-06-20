#include <math.h>
#include <GL/glut.h>
#include <cstdio>
//#include "CollisionObject.h"
class Object {
    public:
        double vertices[4][2];
        
    public:
        Object(double x, double y, double width, double height);
        int coordinates[2];
};
class MotionObject: public Object {
    protected:
        double movement_iter;
    public:
        MotionObject(double x, double y, double width, double height, double m) : Object(x, y, width, height) {
            movement_iter = m;
        }
        void move();
};