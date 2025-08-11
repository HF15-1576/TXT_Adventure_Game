#pragma once

#include <string>
#include "Player.h"

class CommandParser 
{
private:
    // Handlers for supported verbs
    void handleGoCommand(const std::string& noun, Player& player);
    void handlePickupCommand(const std::string& noun, Player& player);
    void handleCheckCommand(const std::string& noun, Player& player);

    // Helper to convert string to lowercase
    std::string toLower(const std::string& str);
public:
    void processCommand(const std::string& input, Player& player);
};