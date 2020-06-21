#include "CollisionObject.h"
class Object {
    public:
        CollisionObject hitbox;
    public:
        Object(double x, double y, double width, double height);
        bool check_collisions(std::vector<Object> objects);

};
class MotionObject: public Object {
    private:
        double x_move;
        double y_move;
        bool momentum;
        int friction;
    public:
        MotionObject(double x, double y, double width, double height) : Object(x, y, width, height){
            momentum = false; friction = 0; x_move=0; y_move=0;
        }
        MotionObject(double x, double y, double width, double height,int f) : Object(x, y, width, height){
            momentum =true; friction = f; x_move=0; y_move=0;
        }

        bool check_move(int dx,int dy, std::vector<Object> objects);

        void force_move(int dx,int dy);

        void move(int dx,int dy, std::vector<Object> objects);
    
};