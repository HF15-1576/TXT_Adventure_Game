#include "Player.h"
#include <algorithm>

Player::Player()
    : battery(100)
    , quality(0)
    , length(0)
    , currentRoomIndex(0) {}

int Player::GetBattery() const {
    return battery;
}

void Player::DrainBattery(int amount) {
    battery =- amount;
    if (battery < 0) battery = 0; 
}

bool Player::IsDead() const {
    return battery <= 0;
}

int Player::GetQuality() const {
    return quality;
}

void Player::AddQuality(int amount) {
    quality += amount;
}

int Player::GetLength() const {
    return length;
}

void Player::AddLength(int amount) {
    length += amount;
}

const std::vector<std::string>& Player::GetInventory() const {
    return inventory;
}

void Player::AddToInventory(const std::string& item, int qualityBoost = 0) 
{
    inventory.push_back(item);
    if (qualityBoost > 0) {
        AddQuality(qualityBoost);
    }
}

void Player::UseItem(const std::string& item) 
{
    // Find the index of the item in inventory
    int index = -1;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i] == item) {
            index = static_cast<int>(i);
            break;
        }
    }

    if (index != -1) {
        inventory.erase(inventory.begin() + index);
        std::cout << "Used item: " << item << std::endl;
    } else {
        std::cout << "You don't have: " << item << std::endl;
    }
}
