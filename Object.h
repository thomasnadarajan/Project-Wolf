#include "CollisionObject.h"
<<<<<<< HEAD
#include <GL/glut.h>
class Object {
    public:
        CollisionObject hitbox;
=======
class Object {
    public:
        CollisionObject hitbox;
    public:
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b
        Object(double x, double y, double width, double height);
        bool check_collisions(std::vector<Object> objects);

};
class MotionObject: public Object {
    private:
<<<<<<< HEAD
        double x_move;
        double y_move;
=======
        int x_vel;
        int y_vel;
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b
        bool momentum;
        int friction;
    public:
        MotionObject(double x, double y, double width, double height) : Object(x, y, width, height){
<<<<<<< HEAD
            momentum = false; friction = 0; x_move=0; y_move=0;
        }
        MotionObject(double x, double y, double width, double height,int f) : Object(x, y, width, height){
            momentum =true; friction = f; x_move=0; y_move=0;
        }
=======
            momentum = false; friction = 0; x_vel=0; y_vel=0;
        }
        MotionObject(double x, double y, double width, double height,int f) : Object(x, y, width, height){
            momentum =true; friction = f; x_vel=0; y_vel=0;
        }
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b

        bool check_move(int dx,int dy, std::vector<Object> objects);

        void force_move(int dx,int dy);

        void move(int dx,int dy, std::vector<Object> objects);
<<<<<<< HEAD
=======
    
>>>>>>> 70ad318e5126989ae0c5c144700c1cf613e70c2b
};