#ifndef SPR
#define SPR
#include "Map.h"
#include <map>
#include <string>
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

class Sprite: public MotionObject{
    public:
        Sprite(int x, int y, int width, int height);
        Map * m;
        std::map<std::string, int> properties; // contains information about object:
        /*
        eg:
        properties = {"can_take_damage": 0, "health": 200, "collision": 1}
        */
        void init(); // activates when originally outside player render range but not anymore

        void update(); // where all the changes will be made.


        void update_map(); // updates the sprites information on the map, like chunk,ect

        std::vector<Object> return_collisions(Object area); //returns (using the map) objects inside an area
        
        void create_damage(Object damage_area, int damage); //create a damaging hitbox

        void take_damage(int damage);

        void move(std::vector<int,int> coord);

        void get_momentum(std::vector<int,int> coord);

        void hide();

        void destroy();
};

class AI_Sprite : public Sprite {
    public:
        AI_Module ai_mod;

};
#endif
