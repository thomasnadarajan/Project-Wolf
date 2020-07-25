#include <iostream>
#include "Game.h"
Player::Player(double x, double y, double width, double height, Map * m) : MotionObject(x, y, width, height, m) {
    health_points = 100;
}

Game::Game(double x, double y, double width, double height) : p(x, y, width, height, &m) {

}
void Chunk::add_object(double x, double y, double width, double height, int motion, double incr, Map * ref) {
    if (motion == 1) {
        MotionObject o(x, y, width, height, incr, ref);
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
void Player::draw() {
    glPushMatrix();
    glRotatef(theta, 0, 1, 0);
    glPopMatrix();
    glBegin(GL_QUADS);
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x), coord_to_screen(hitbox.main_hitbox.y));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x + hitbox.main_hitbox.width), coord_to_screen(hitbox.main_hitbox.y ));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x + hitbox.main_hitbox.width), coord_to_screen(hitbox.main_hitbox.y + hitbox.main_hitbox.height));
    glVertex2f(coord_to_screen(hitbox.main_hitbox.x), coord_to_screen(hitbox.main_hitbox.y + hitbox.main_hitbox.height));
    glEnd();
    glFlush();
    
}
void Game::draw() {
    auto pos_tup = std::make_tuple(0,0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);     
    p.draw();
    std::vector<Object> objs = m.get_nearby_objects(pos_tup);
    for (auto obj : objs) {
        obj.draw();
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
        c.add_object(std::get<0>(elem), std::get<1>(elem), std::get<2>(elem), std::get<3>(elem), std::get<4>(elem), std::get<5>(elem), NULL);
    }
    chunks.insert(std::pair<std::tuple<int, int>, Chunk>(set, c));
}
std::vector<Object>& Chunk::get_objects() {
    return objects;
}
std::tuple<int, int> Map::get_chunk(std::tuple<int, int> set) {
    int a = std::get<0>(set);
    int b = std::get<1>(set);
    if (a<0){
        a = (a/100)-1;
    }
    else {
        a /= 100;
    }
    if (b < 0){
        b = (b/100)-1;
    }
    else {
        b /= 100;
    }
    return std::make_tuple(a, b);
}



std::vector<Object> Map::get_nearby_objects(std::tuple<int, int> position){
    std::tuple<int, int> a = get_chunk(position);
    std::vector<Object> ans = {};
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            std::tuple<int, int> x = std::make_tuple(std::get<0>(a)+dx, std::get<0>(a)+dy);
            if (chunks.count(x)){
                ans.insert(ans.end(), chunks[x].get_objects().begin(), chunks[x].get_objects().end());
            }
        }
    }
    return ans;

}

void Game::update() {
    p.update();
    auto pos_tup = std::make_tuple(p.hitbox.main_hitbox.x, p.hitbox.main_hitbox.y);
    auto objs = m.get_nearby_objects(pos_tup);
    for (auto obj : objs) {
        obj.update();
    }
}


void Player::move(std::vector<Object> objs, int key) {
    if (!momentum) {
        if (key == GLUT_KEY_LEFT && x_vel >=0) {
            x_vel += -2;
        }
        if (key ==GLUT_KEY_RIGHT && x_vel <=0) {
            x_vel += 2;
        }
        if (key == GLUT_KEY_UP && y_vel <=0) {
            y_vel += 2;
        }
        if (key == GLUT_KEY_DOWN && y_vel >= 0) {
            y_vel += -2;
        }
    }
    else {
        if (key == GLUT_KEY_LEFT) {
            x_vel += -2;
        }
        if (key ==GLUT_KEY_RIGHT) {
            x_vel += 2;
        }
        if (key == GLUT_KEY_UP) {
            y_vel += 2;
        }
        if (key == GLUT_KEY_DOWN) {
            y_vel += -2;
        }
    }
}