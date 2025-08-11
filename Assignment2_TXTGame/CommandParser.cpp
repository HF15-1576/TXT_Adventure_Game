#include "CommandParser.h"
#include <iostream>
#include <algorithm> 

// Helper function to convert string to lowercase
static std::string toLower(const std::string& str) 
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

void CommandParser::processCommand(const std::string& input, Player& player) 
{
    // Find first space
    size_t spacePos = input.find(' ');
    std::string verb, noun;

    if (spacePos == std::string::npos) {
        // No space found - command isn't two words
        std::cout << "Please enter a command with exactly two words (e.g. 'Go North').\n";
        return;
    }

    // Extract verb and noun, trimming trailing spaces from noun
    verb = input.substr(0, spacePos);
    noun = input.substr(spacePos + 1);

    // Trim trailing spaces from noun
    size_t endPos = noun.find_last_not_of(' ');
    if (endPos != std::string::npos) {
        noun = noun.substr(0, endPos + 1);
    } else {
        noun.clear(); // noun was all spaces
    }

    // Convert to lowercase
    verb = toLower(verb);
    noun = toLower(noun);

    // Check for empty parts
    if (verb.empty() || noun.empty()) {
        std::cout << "Please enter a command with exactly two words (e.g. 'Go North').\n";
        return;
    }

    if (verb == "go") {
        handleGoCommand(noun, player);
    }
    else if (verb == "pickup") {
        handlePickupCommand(noun, player);
    }
    else if (verb == "check") {
        handleCheckCommand(noun, player);
    }
    else {
        std::cout << "Unknown command: '" << verb << "'. Try commands like 'Go North' or 'Pickup Battery'.\n";
    }
}

void CommandParser::handleGoCommand(const std::string& noun, Player& player) 
{
    if (noun == "north" || noun == "south" || noun == "east" || noun == "west") {
        // TODO: Integrate movement system (Person 1)
        std::cout << "You move " << noun << ".\n";
        player.drainBattery(7);
        player.addLength(1);

        if (player.isDead()) {
            std::cout << "Your camera battery died. Game over.\n";
        }
    }
    else {
        std::cout << "You can't go '" << noun << "'. Try north, south, east, or west.\n";
    }
}

void CommandParser::handlePickupCommand(const std::string& noun, Player& player) 
{
    if (noun == "battery") {
        // TODO: Check if battery exists in current room (Person 1)
        std::cout << "You pick up the battery and recharge your camera.\n";
        player.drainBattery(-20);  // recharge 20%
    }
    else {
        std::cout << "There is no '" << noun << "' here to pick up.\n";
    }
}

void CommandParser::handleCheckCommand(const std::string& noun, Player& player) 
{
    if (noun == "battery") {
        std::cout << "Battery level: " << player.getBattery() << "%\n";
    }
    else if (noun == "inventory") {
        const auto& inv = player.getInventory();
        if (inv.empty()) {
            std::cout << "Your inventory is empty.\n";
        }
        else {
            std::cout << "Inventory:\n";
            for (const auto& item : inv) {
                std::cout << "- " << item << "\n";
            }
        }
    }
    else {
        std::cout << "I don't know how to check '" << noun << "'.\n";
    }
}
