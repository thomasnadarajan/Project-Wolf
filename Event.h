typedef struct PLAYER_MOVE {
    int dx;
    int dy;
} PLAYER_MOVE;
typedef struct PLAYER_ROTATE {
} PLAYER_ROTATE;
typedef struct AI_MOVE {
    int dx;
    int dy;
} AI_MOVE;

typedef struct PLAYER_ATTACK {

} PLAYER_ATTACK;

typedef struct Event {
    PLAYER_MOVE * pm;
    AI_MOVE * am;
    PLAYER_ATTACK * pa;
} Event;