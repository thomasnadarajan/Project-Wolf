#include "Object.h"
#include <vector>
#include <map>
#include <tuple>
class Player: public MotionObject {
    private:
        int health_points;
    public:
        Player(double x, double y, double width, double height, double move): MotionObject(x, y, width, height, move);
};
class Chunk {
    public:
        std::vector<Object> chunk_objects;
        Chunk(std::vector<Object> objs);
};
class Map {
    private:
        std::map<std::tuple<int, int>, Chunk> maps;

};

class Game {
    private:
        int running;
        double move;
        int game_over;
        Player p;
        std::vector<Object> objects;
    public:
        Game(double x, double y, double width, double height, double move);
        void add_object(double x, double y, double width, double height, int motion);
};



