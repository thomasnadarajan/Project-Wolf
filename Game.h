#include "Draw.h"
//#include "EventFunctions.h"
#include <vector>
#include <map>
#include <tuple>

class Game {
    public:
        Map m;
        int running;
        double move;
        int game_over;
        Player p;
        std::vector<std::tuple<void (*)(Sprite*), Sprite *>> event_queue;
        Game(double x, double y, double width, double height, double move);
        void init();
        void cleanup();
        void handle_events();
        void draw();
        void update();
        void enqueue(void (*fun)(Sprite*), Sprite * s);
};



