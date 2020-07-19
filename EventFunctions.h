#include "Game.h"

void patrolmode_ai(Sprite& s) {
    AI_Sprite * same = &s;
    if (same->patrol_left) {
        if (cur_ind == 0) {
            same->patrol_left = 0;
            same->patrol_right = 1;
        }
        else {
            cur_ind -= 1;
        }
    }
    else {
        if (cur_ind == same->path_size -1) {
            same->patrol_left = 1;
            same->patrol_right = 0;
        }
        else {
            cur_ind += 1;
        }
    }
}

void move_toward_player_ai(Sprite& s) {
    // Rotate and move along axis.
    

}


void player_attack(Sprite& s) {

}

void player_rotate(Sprite& s) {
    
}
