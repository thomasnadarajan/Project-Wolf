#include <vector>
#include <map>
#include <tuple>
#include "Object.h"

class Player: public MotionObject {
    private:
        int health_points;
    public:
        Player(double x, double y, double width, double height, Map * m);
        void move(std::vector<Object> objs, int key);

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



