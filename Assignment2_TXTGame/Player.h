#pragma once

#include <string>
#include <vector>

class Player {
private:
    int battery;
    int quality;
    int length;
    int currentRoomIndex;
    std::vector<std::string> inventory;  // clues or items collected

public:
    // Constructor
    Player();

    // Player methods
    int getBattery() const;
    void drainBattery(int amount);
    bool isDead() const;

    int getQuality() const;
    void addQuality(int amount);

    int getLength() const;
    void addLength(int amount);

    bool hasClue(const std::string& clue) const;
    void addClue(const std::string& clue);

    int getCurrentRoom() const;
    void SetCurrentRoom(int roomIndex);

    const std::vector<std::string>& getInventory() const;
};