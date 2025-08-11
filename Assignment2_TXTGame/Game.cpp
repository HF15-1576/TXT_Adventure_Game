#include <iostream>
#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include "Room.h"
#include "GameState.h"

int currentRoomIndex = 0;
std::vector<Room> rooms;
GameState gameState;

// Moves player forward through the shuffled rooms
void goForward() {
    if (currentRoomIndex >= static_cast<int>(rooms.size()) - 1) {
        std::cout << "You've reached the end of the motel.\n";
        gameState.gameOver = true;
        return;
    }

    currentRoomIndex++;
    gameState.length++;

    // Drain battery 5-10%
    int drain = (rand() % 6) + 5;
    gameState.battery -= drain;
    if (gameState.battery < 0) gameState.battery = 0;

    Room& room = rooms[currentRoomIndex];
    std::cout << "You enter the " << room.name << ".\n";

    if (!room.visited) {
        std::cout << "[Show dialog section: " << room.introSection << "]\n";
        room.visited = true;

        if (room.hasBattery) {
            std::cout << "You find a battery pack and recharge your camera.\n";
            gameState.battery += 20;
            if (gameState.battery > 100) gameState.battery = 100;
        }
        if (room.hasClue) {
            std::cout << "You find a clue for the safe.\n";
            gameState.quality += 5;
        }
        if (room.hasSquatter) {
            std::cout << "You encounter a squatter. Be careful!\n";
            gameState.quality += 3;
        }
    }
    else {
        std::cout << "You've been here before. Nothing new.\n";
    }

    std::cout << "Battery: " << gameState.battery << "%\n";
    std::cout << "Video Quality: " << gameState.quality << "\n";
    std::cout << "Video Length: " << gameState.length << "\n";

    if (gameState.battery == 0) {
        std::cout << "Your camera battery has died. The recording ends.\n";
        gameState.gameOver = true;
    }
}

// Moves player back one room if possible
void goBack() {
    if (currentRoomIndex <= 0) {
        std::cout << "You are at the motel entrance. Can't go back further.\n";
        return;
    }
    currentRoomIndex--;
    std::cout << "You go back to the " << rooms[currentRoomIndex].name << ".\n";

    // No battery drain when going back (can change if you want)
    Room& room = rooms[currentRoomIndex];
    std::cout << "[Show dialog section: " << room.introSection << "]\n";
}

// Prints simple instructions
void printHelp() {
    std::cout << "Commands:\n";
    std::cout << "  Go Forward\n";
    std::cout << "  Go Back\n";
    std::cout << "  Quit\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    rooms = createRooms();
    currentRoomIndex = 0;

    std::cout << "Welcome to the Abandoned Motel Exploration Game!\n";
    std::cout << "Your camera battery starts at 100%.\n";
    std::cout << "Explore rooms to improve your video quality and length.\n\n";

    // Show first room intro
    std::cout << "You enter the " << rooms[currentRoomIndex].name << ".\n";
    std::cout << "[Show dialog section: " << rooms[currentRoomIndex].introSection << "]\n";

    std::string command;
    printHelp();

    while (!gameState.gameOver) {
        std::cout << "\n> ";
        getline(std::cin, command);

        if (command == "Go Forward" || command == "go forward") {
            goForward();
        }
        else if (command == "Go Back" || command == "go back") {
            goBack();
        }
        else if (command == "Quit" || command == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else {
            std::cout << "Unknown command. Try again.\n";
            printHelp();
        }
    }

    // Simple ending logic
    if (gameState.gameOver) {
        std::cout << "\nGame Over!\n";
        std::cout << "Final Video Quality: " << gameState.quality << "\n";
        std::cout << "Final Video Length: " << gameState.length << "\n";

        if (gameState.quality >= 10 && gameState.length >= 3) {
            std::cout << "Your video goes viral! Congratulations!\n";
        }
        else if (gameState.quality >= 5) {
            std::cout << "Your video gets some views, not bad.\n";
        }
        else {
            std::cout << "Your video is boring and gets no views.\n";
        }
    }

    return 0;
}