#include "CollisionObject.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif
#include <tuple>
#include <map>
double coord_to_screen(int x);
class Map;
class Object {
    public:
        bool terrain;
        CollisionObject hitbox;
        Object(double x, double y, double width, double height);
        bool check_collisions(std::vector<Object> * objects);
        virtual void update();
        bool check_object_collision(Object& o);
        void draw();
        std::tuple<int, int> return_coords() {
            auto tup = std::make_tuple(hitbox.main_hitbox.x, hitbox.main_hitbox.y);
            return tup;
        }
};
class Chunk {
    public:
        //Chunk();    
        //Chunk(std::vector<Object> all_objects_for_chunk);
        std::vector<Object *> objects;
        void add_object(double x, double y, double width, double height, int motion, double incr, Map * ref);
        std::vector<Object *>& get_objects();
        bool tiles[20][20];
        bool get_tile(int x, int y);
        void set_tile(int x, int y, bool truth);
};
class Map {
    public:
        int width;
        int height;
        void add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set);
        void set_props(int width, int height);
        std::tuple<int, int> get_chunk(std::tuple<int, int> position);
        std::vector<Object*> get_nearby_objects(std::tuple<int, int> position);
        std::map<std::tuple<int, int>, Chunk> chunks;
        Chunk * current_chunk;
        //void update_obj_current_chunk(Object *);
};

class MotionObject: public Object {
    public:
        Map * map_ref;
        int x_vel;
        int y_vel;
        bool momentum;
        int friction;
        MotionObject(double x, double y, double width, double height, Map * map_ref) : Object(x, y, width, height){
            momentum = false; friction = 0; x_vel=0; y_vel=0;
            this->map_ref = map_ref;
        }
        MotionObject(double x, double y, double width, double height,int f, Map * map_ref) : Object(x, y, width, height){
            momentum =true; friction = f; x_vel=0; y_vel=0;
            this->map_ref = map_ref;
        }
        bool check_move(int dx,int dy, std::vector<Object> * objects);
        void force_move(int dx,int dy);
        void move(int dx,int dy, std::vector<Object *> objects);
        void update() override;
        bool check_velocity();
};