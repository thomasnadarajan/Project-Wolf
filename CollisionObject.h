#include <iostream>
#include <vector>
#include "Object.h"
class Hitbox {
    public:
        int coords[2];
        int size[2];
        
};
class Collision {
    private:
        std::vector<Hitbox> hitboxes;
        int num_hitboxes;
        Hitbox central_hitbox;
    public:
        Collision(Object& o) {
            
        }

}