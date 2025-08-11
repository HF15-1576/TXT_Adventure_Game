#ifndef GAMESTATE_H
#define GAMESTATE_H

struct GameState {
    int battery = 100;  // Battery percentage (0-100)
    int quality = 0;    // Quality points for the video
    int length = 0;     // Number of rooms explored
    bool gameOver = false;
};

#endif // GAMESTATE_H