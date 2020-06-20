#include "Object.h"
#include <vector>
#include <unordered_map> 
class Player: public MotionObject {
    private:
        int health_points;
        //Collision col(this);
    public:
        Player(double x, double y, double width, double height, double move): MotionObject(x, y, width, height, move) {
            health_points = 100;
        }
};

class Game {
    private:
        int running;
        double move;
        int game_over;
        Player p;
        std::vector<Object> objects;
    public:
        Game(double x, double y, double width, double height, double move) {
            p(x, y, width, height, move);
        }
        void add_object(double x, double y, double width, double height, int motion) {
            if (motion == 1) {
                MotionObject o(x, y, width, height, );
                objects.insert(o);
            }
            else {
                Object o(x, y, width, height);
                objects.insert(o);
            }
        }

};

class Map {
    private:
        std::unordered_map<

}

