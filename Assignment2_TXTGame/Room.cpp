#include "Room.h"
#include <algorithm>
#include <random>

std::vector<Room> createRooms() 
{
    std::vector<Room> rooms = 
    {
		{"Parking Lot", "ROOM1_INTRO", "ROOM1_EVENT", false, false, false, false, false, nullptr},
        {"Lobby", "ROOM2_INTRO", "ROOM2_EVENT", false, true, false, false, false, nullptr},
        {"Hallway", "ROOM3_INTRO", "ROOM3_EVENT", false, false, false, false, false, nullptr},
        {"Laundry Room", "ROOM4_INTRO", "ROOM4_EVENT", false, false, true, false, false, nullptr},
        {"Storage Closet", "ROOM5_INTRO", "ROOM5_EVENT", false, true, false, false, false, nullptr},
        {"Manager's Office", "ROOM6_INTRO", "ROOM6_EVENT", false, false, true, false, true, nullptr},
        {"Vacant Room 101", "ROOM7_INTRO", "ROOM7_EVENT", false, false, true, true, false, nullptr},
        {"Vacant Room 102", "ROOM8_INTRO", "ROOM8_EVENT", false, false, false, false, false, nullptr},
        {"Vacant Room 103", "ROOM9_INTRO", "ROOM9_EVENT", false, false, true, false, false, nullptr},
        {"Vacant Room 104", "ROOM10_INTRO", "ROOM10_EVENT", false, false, false, false, false, nullptr},
        {"Vacant Room 105", "ROOM11_INTRO", "ROOM11_EVENT", false, false, true, false, false, nullptr},
        {"Rooftop Access", "ROOM12_INTRO", "ROOM12_EVENT", false, false, false, false, false, nullptr},
        {"Lobby Bathroom", "ROOM13_INTRO", "ROOM13_EVENT", false, false, false, false, false, nullptr}
    };

    // Shuffle rooms randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rooms.begin(), rooms.end(), g);

    return rooms;
}