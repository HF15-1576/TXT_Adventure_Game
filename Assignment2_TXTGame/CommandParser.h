#pragma once

#include <string>
#include "Player.h"

class CommandParser 
{
private:
    // Handlers for supported verbs
    void HandleGoCommand(const std::string& noun, Player& player);
    void HandlePickupCommand(const std::string& noun, Player& player);
    void HandleUseCommand(const std::string& noun, Player& player);
    void HandleInventoryCommand(const std::string& noun, Player& player);
    bool CheckInventory(const std::string& item, Player& player);

    // Helper to convert string to lowercase
    std::string ToLower(const std::string& str);
public:
    void ProcessCommand(const std::string& input, Player& player);
};
