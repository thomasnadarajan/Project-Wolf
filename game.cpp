#include <iostream>
#include "Game.h"
Player::Player(double x, double y, double width, double height, double move) : MotionObject(x, y, width, height, move) {
    health_points = 100;
}

Game::Game(double x, double y, double width, double height, double move) : p(x, y, width, height, move) {}
void Chunk::add_object(double x, double y, double width, double height, int motion, double incr) {
    if (motion == 1) {
        MotionObject o(x, y, width, height, incr);
        objects.push_back(o);
    }
    else {
        Object o(x, y, width, height);
        objects.push_back(o);
    }
}
void Map::set_props(int width, int height) {
    this->width = width;
    this->height = height;
}
void Map::add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set) {
    Chunk c;
    for (auto elem : vect) {
        c.add_object(std::get<0>(elem), std::get<1>(elem), std::get<2>(elem), std::get<3>(elem), std::get<4>(elem), std::get<5>(elem));
    }
    chunks.insert(std::pair<std::tuple<int, int>, Chunk>(set, c));
    Chunk q = get_chunk(set);
    std::vector<Object> objs = q.get_objects();
    Object a = (objs)[0];
    printf("%d\n", a.hitbox.main_hitbox.height);
}
std::vector<Object>& Chunk::get_objects() {
    return objects;
}
Chunk& Map::get_chunk(std::tuple<int, int> set) {
    //Chunk& ref;
    for (auto elem : chunks) {
        if ((std::get<0>(set) >= std::get<0>(elem.first) && std::get<0>(set) < std::get<0>(elem.first) + width) &&
            (std::get<1>(set) >= std::get<1>(elem.first) && std::get<0>(set) < std::get<1>(elem.first) + height)) {
                return std::get<1>(elem);
                //break;
            }
    }
    //return new Chunk;
}

void Player::move(Chunk& cur_chunk, int key) {
    if (key == GLUT_KEY_LEFT) {
        MotionObject::move(-1, 0, (cur_chunk.get_objects()));
    }
    else if (key ==GLUT_KEY_RIGHT) {
        MotionObject::move(1, 0,(cur_chunk.get_objects()));
    }
    else if (key == GLUT_KEY_UP) {
        MotionObject::move(0, 1,(cur_chunk.get_objects()));
    }
    else if (key == GLUT_KEY_DOWN) {
        MotionObject::move(0, -1,(cur_chunk.get_objects()));
    }
}