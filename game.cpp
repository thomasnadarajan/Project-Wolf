#include <iostream>
#include "Game.h"
Player::Player(double x, double y, double width, double height, double move){
    health_points = 100;
}

Game::Game(double x, double y, double width, double height, double move) {
    p(x, y, width, height, move);
}
void Game::add_object(double x, double y, double width, double height, int motion) {
    if (motion == 1) {
        MotionObject o(x, y, width, height, );
        objects.push_back(o);
    }
    else {
        Object o(x, y, width, height);
        objects.push_back(o);
    }
}

