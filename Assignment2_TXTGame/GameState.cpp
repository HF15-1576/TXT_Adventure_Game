#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <functional>

struct GameState; // Forward declaration

struct Room {
    std::string name;
    std::string introSection;   // Script section for intro dialog
    std::string eventSection;   // Script section for event dialog
    bool visited = false;
    bool hasBattery = false;
    bool hasClue = false;
    bool hasSquatter = false;

    // Optional event function pointer (can be nullptr if unused)
    std::function<void(GameState&, Room&)> eventFunc;
};

// Creates and returns the list of rooms, shuffled randomly
std::vector<Room> createRooms();

#endif // ROOM_H