#include "Draw.h"
#include "Event.h"
#include <vector>
#include <map>
#include <tuple>
class Chunk {
    private:
        std::vector<Object> objects;
    public:
        void add_object(double x, double y, double width, double height, int motion, double incr);
        std::vector<Object>& get_objects();

};
class Player: public MotionObject {
    private:
        int health_points;
    public:
        Player(double x, double y, double width, double height, double move);
        void move(std::vector<Object> objs, int key);
        // Make this a temporary change.
        //std::vector<Object> map;
};

class Map {
    public:
        int width;
        int height;
        void add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set);
        void set_props(int width, int height);
        std::tuple<int, int> get_chunk(std::tuple<int, int> position);
        std::map<std::tuple<int, int>, Chunk> chunks;
};

class Game {
    public:
        Map m;
        int running;
        double move;
        int game_over;
        Player p;
        std::vector<Event> event_stack;
        Game(double x, double y, double width, double height, double move);
        void init();
        void cleanup();
        void handle_events();
        void draw();
};



