#include <vector>
#include <map>
#include "Object.h"
class Chunk {
    private:
        std::vector<Object> objects;
    public:
        void add_object(double x, double y, double width, double height, int motion, double incr);
        std::vector<Object>& get_objects();

};

class Map {
    public:
        int width;
        int height;
        void add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set);
        void set_props(int width, int height);
        std::tuple<int, int> get_chunk(std::tuple<int, int> position);
        std::vector<Object> get_nearby_objects(std::tuple<int, int> position);
        std::map<std::tuple<int, int>, Chunk> chunks;
};