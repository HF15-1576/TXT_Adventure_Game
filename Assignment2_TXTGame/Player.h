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
    // Battery
    int GetBattery() const;
    void DrainBattery(int amount);
    bool IsDead() const;

    // Quality
    int GetQuality() const;
    void AddQuality(int amount);

    // Video Length
    int GetLength() const;
    void AddLength(int amount);

    // Inventory
    const std::vector<std::string>& GetInventory() const;
    void AddToInventory(const std::string& item, int qualityBoost = 0);
    void UseItem(const std::string& item);;
};
