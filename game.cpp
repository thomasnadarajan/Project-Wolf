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
void Game::init() {
    m.set_props(100, 100);
    auto obj_tup = std::make_tuple(30, 30, 10, 20, 0, -1);
    auto pos_tup = std::make_tuple(0,0);
    std::vector<std::tuple<double, double, double, double, int, double>> vect;
    vect.push_back(obj_tup);
    m.add_chunk(vect, pos_tup);
}
void Game::draw() {
    auto pos_tup = std::make_tuple(0,0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);     
    draw_vertices(p);
    auto chunk = m.get_chunk(pos_tup);
    std::vector<Object> objs = m.chunks[chunk].get_objects();
    for (auto obj : objs) {
        draw_vertices(obj);
    }
    glFlush();
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
}
std::vector<Object>& Chunk::get_objects() {
    return objects;
}
std::tuple<int, int> Map::get_chunk(std::tuple<int, int> set) {
    //Chunk& ref;
    for (auto elem : chunks) {
        if ((std::get<0>(set)/ 100.0 >= std::get<0>(elem.first) / 100.0 && std::get<0>(set) /100.0 < (std::get<0>(elem.first) + width) /100.0) &&
            (std::get<1>(set)/ 100.0 >= std::get<1>(elem.first) / 100.0 && std::get<1>(set) /100.0 < (std::get<1>(elem.first) + width) /100.0)) {
                return elem.first;
            }
    }
    return std::make_tuple(-1, -1);
}

void Player::move(std::vector<Object> objs, int key) {
    if (key == GLUT_KEY_LEFT) {
        MotionObject::move(-1, 0, objs);
    }
    else if (key ==GLUT_KEY_RIGHT) {
        MotionObject::move(1, 0,objs);
    }
    else if (key == GLUT_KEY_UP) {
        MotionObject::move(0, 1,objs);
    }
    else if (key == GLUT_KEY_DOWN) {
        MotionObject::move(0, -1,objs);
    }
}