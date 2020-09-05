#ifndef OBJ
#define OBJ
#include <vector>
#include <map>
#include <tuple>
#include "Object.h"

class Player: public MotionObject {
    private:
        int health_points;
    public:
        double theta;
        bool keyState[246];
        Player(double x, double y, double width, double height, Map * m);
        void move(int key);
        void draw();

};
class Game {
    public:
        Map m;
        int running;
        double move;
        int game_over;
        Player p;
        Chunk * current_chunk;
        Game(double x, double y, double width, double height);
        void init();
        void cleanup();
        void handle_events();
        void draw();
        void update();
};
#endif