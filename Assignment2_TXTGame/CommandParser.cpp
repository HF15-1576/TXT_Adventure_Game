#include "CommandParser.h"
#include <iostream>
#include <algorithm>

// Make this a private static helper inside CommandParser, or keep as free function if preferred
std::string CommandParser::ToLower(const std::string& str) 
{
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return result;
}

void CommandParser::ProcessCommand(const std::string& input, Player& player) 
{
    std::string command = ToLower(input);
    size_t spacePos = command.find(' ');
    std::string verb = command.substr(0, spacePos);
    std::string noun = (spacePos != std::string::npos) ? command.substr(spacePos + 1) : "";

    if (verb == "go") {
        HandleGoCommand(noun, player);
    } else if (verb == "pickup") {
        HandlePickupCommand(noun, player);
    } else if (verb == "use") {
        HandleUseCommand(noun, player);
    } else if (verb == "inventory") {
        CheckInventory(noun, player);
    } else {
        std::cout << "Unknown command: " << input << std::endl;
    }
}

void CommandParser::HandleGoCommand(const std::string& noun, Player& player) 
{
    // Example implementation
    if (noun.empty()) 
    {
        std::cout << "Go where?" << std::endl;
    } else 
    {
        
    }
}

void CommandParser::HandlePickupCommand(const std::string& noun, Player& player) 
{
    // Example implementation
    if (noun.empty()) 
    {
        std::cout << "Pickup what?" << std::endl;
    } else 
    {
        player.AddToInventory(noun);
        std::cout << "Picked up: " << noun << std::endl;
    }
}

void CommandParser::HandleUseCommand(const std::string& noun, Player& player) 
{
    // Example implementation
    if (noun.empty()) 
    {
        std::cout << "Use what?" << std::endl;
    } else 
    {
        if (CheckInventory(noun, player)) 
        {
            std::cout << "Using: " << noun << std::endl;
            // Implement the logic for using the item
        } else 
        {
            std::cout << "You don't have: " << noun << std::endl;
        }
    }
}

bool CommandParser::CheckInventory(const std::string& item, Player& player) 
{
    const std::vector<std::string>& inventory = player.GetInventory();
    return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
}

