#ifndef SPR
#define SPR
#include "Map.h"
#include <map>
class Player: public MotionObject {
    private:
        int health_points;
    public:
        Player(double x, double y, double width, double height, double move);
        void move(std::vector<Object> objs, int key);

};


class AI_Module {
    public:
        int patrol_left;
        int patrol_right;
        Player * p;
        std::vector<std::tuple<int, int>> patrol_path;
        int curr_pos;
        int path_size;
};

class Sprite {
    public:
        Object o;
        int allegiance;
        Sprite(Object& obj, int allegiance) : o(obj) {
            this->allegiance = allegiance;
        }
        Map * m;
};

class AI_Sprite : public Sprite {
    public:
        AI_Module ai_mod;

};
#endif
