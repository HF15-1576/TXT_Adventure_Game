#include "Player.h"
#include <algorithm>

Player::Player()
    : battery(100)
    , quality(0)
    , length(0)
    , currentRoomIndex(0) {}

int Player::getBattery() const {
    return battery;
}

void Player::drainBattery(int amount) {
    battery = std::max(0, battery - amount);
}

bool Player::isDead() const {
    return battery <= 0;
}

int Player::getQuality() const {
    return quality;
}

void Player::addQuality(int amount) {
    quality += amount;
}

int Player::getLength() const {
    return length;
}

void Player::addLength(int amount) {
    length += amount;
}

bool Player::hasClue(const std::string& clue) const {
    return std::find(inventory.begin(), inventory.end(), clue) != inventory.end();
}

void Player::addClue(const std::string& clue) {
    if (!hasClue(clue)) {
        inventory.push_back(clue);
        addQuality(5); // For example, picking up clues improves quality
    }
}

int Player::getCurrentRoom() const {
    return currentRoomIndex;
}

void Player::SetCurrentRoom(int roomIndex) {
    currentRoomIndex = roomIndex;
}

const std::vector<std::string>& Player::getInventory() const {
    return inventory;
}
