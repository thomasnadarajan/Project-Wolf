#include <iostream>
#include "Game.h"
Player::Player(double x, double y, double width, double height, double move) : MotionObject(x, y, width, height, move){
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

void Map::add_chunk(std::vector<std::tuple<double, double, double, double, int, double>> vect, std::tuple<int, int> set) {
    Chunk c;
    for (auto elem : vect) {
        c.add_object(std::get<0>(elem), std::get<1>(elem), std::get<2>(elem), std::get<3>(elem), std::get<4>(elem), std::get<5>(elem));
    }
    chunks.insert(std::pair<std::tuple<int, int>, Chunk>(set, c));
}