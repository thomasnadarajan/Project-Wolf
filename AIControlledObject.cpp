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
    Tile * current_ref = map_ref->player_pos;
    while (returned[current_ref] != current_tile) {
        current_ref = returned[current_ref];
    }
    
}