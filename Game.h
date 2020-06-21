#include "Draw.h"
#include <vector>
#include <map>
#include <tuple>
class Player: public MotionObject {
    private:
        int health_points;
    public:
        Player(double x, double y, double width, double height, double move);
        void move(int key);
};
class Chunk {
    private:
        std::vector<Object> objects;
    public:
        void add_object(double x, double y, double width, double height, int motion, double incr);
};
class Map {
    private:
        std::map<std::tuple<int, int>, Chunk> chunks;
    public:
        void add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set);
};

class Game {
    public:
        int running;
        double move;
        int game_over;
        Player p;
        Game(double x, double y, double width, double height, double move);
};



