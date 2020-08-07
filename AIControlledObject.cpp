#include "AIControlledObject.h"

std::map<Tile*, Tile*> AIControlledObject::recalculate_distance (Tile * t) {
    std::vector<Tile *> marked;
    marked.push_back(t);
    std::map<Tile *, int> distance;
    std::map<Tile *, Tile *> previous;
    distance[t] = 0;
    std::queue<Tile *> tile_queue;
    tile_queue.push(t);
    while (tile_queue.empty() == false) {
        Tile * deq = tile_queue.front();
        tile_queue.pop();
        for (Tile * elem : deq->edges) {
            int i = 0;
            for (auto mark : marked) {
                if (mark == elem) {
                    i = 1;
                }
            }
            if (!i) {
                distance[elem] = distance[deq] + 1;
                previous[elem] = deq;
                tile_queue.push(elem);
                marked.push_back(elem);
            }
        }
    }
    return previous;
}

void AIControlledObject::update() {
    auto returned = recalculate_distance(current_tile);
    Tile * next_tile = map_ref->player_pos;
    while (returned[next_tile] != current_tile) {
        next_tile = returned[next_tile];
    }
    if (hitbox.main_hitbox.x < returned[next_tile]->x + 25 && hitbox.main_hitbox.y < returned[next_tile]->y + 25) {
        current_tile = returned[next_tile];
        AIControlledObject::update();
    }
    else {
        if (next_tile->x < current_tile->x) {
            x_vel = -2;
        }
        else if (next_tile->x > current_tile->x) {
            x_vel = 2;
        }
        else {
            x_vel = 0;
        }
        if (next_tile->y < current_tile->y) {
            y_vel = -2;
        }
        else if (next_tile->y > current_tile->y) {
            y_vel = 2;
        }
        else {
            y_vel = 0;
        }
    }
}