#ifndef HEADER_SETTINGS
#define HEADER_SETTINGS

class Settings {
public:
    // Constants (unchangeable values)
    static const int WINDOW_WIDTH ;
    static const int WINDOW_HEIGHT;
    static const int PIPE_WIDTH;
    static const int PIPE_GAP;
    // Variables (can be updated)
    static float GRAVITY;
    static float SPEED;
    static float JUMP_STRENGTH;
    static const float CAT_WIDTH ;
    static const float CAT_HEIGHT;
};
#endif

