#include "Game.h"
#include "Consumable.h"
#include "String.h"

#include <random>

Game::Game() {
	MakeRooms();
}

Game::~Game() {}

void Game::Run() {
	String commands[] = {
		"move north", "move south", "move east", "move west", "use ", "look", "quit", "help"
	};
	int playerPosX = 2;
	int playerPosY = 2;
	std::cout << "\t\tWELCOME TO THE DUNGEON." << std::endl << std::endl;
	std::cout << "\t\tPress 'Enter' to start.";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	while (true) {
		system("cls");
		std::cout << "\t\t"<< rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n\n";
		rooms[playerPosY][playerPosX]->Description();
		DisplayValidDirections(playerPosX, playerPosY);
		String input;
		String itemName;
		if (rooms[playerPosY][playerPosX]->GetItem() != nullptr) itemName = rooms[playerPosY][playerPosX]->GetItem()->GetName();
		else itemName = "";

		std::cout << "\n\n\t\t>> ";
		input.ReadFromConsole();

		std::cout << "\n";

		if (input == commands[0] && playerPosY > 0) playerPosY--;
		else if (input == commands[1] && playerPosY < MAP_HEIGHT - 1) playerPosY++;
		else if (input == commands[2] && playerPosX < MAP_WIDTH - 1) playerPosX++;
		else if (input == commands[3] && playerPosX > 0) playerPosX--;
		else if (input == commands[4] + itemName.ToLower()) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			rooms[playerPosY][playerPosX]->GetItem()->Use();
		}
		else if (input == commands[5]) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			if (rooms[playerPosY][playerPosX]->GetItem() == nullptr) std::cout << "\n\t\tYou see nothing of value here.\n";
			else rooms[playerPosY][playerPosX]->GetItem()->Description();
		}
		else if (input == commands[6]) break;
		else if (input == commands[7]) {
			system("cls");
			std::cout << "\t\t[Valid Commands]\n\n"
				<< "\t\tMove <direction>\n"
				<< "\t\tLook\n"
				<< "\t\tUse <item name>\n"
				<< "\t\tHelp\n"
				<< "\t\tQuit\n";
		}
		else {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n\n";
			std::cout << std::endl << "\t\tInvalid Command!";
		} 

		std::cout << "\n\n\t\tPress 'Enter' to continue.";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();

	}
}

void Game::DisplayValidDirections(int x, int y) {
	std::cout << "\t\tYou can go: "
		<< ((y > 0) ? "north, " : "")
		<< ((x < MAP_WIDTH - 1) ? "east, " : "")
		<< ((y < MAP_HEIGHT - 1) ? "south, " : "")
		<< ((x > 0) ? "west, " : "") << std::endl;
}

void Game::MakeRooms() {
	//std::cout << "Generating rooms...\n";
	std::random_device rand;
	std::mt19937 generator(rand());
	std::uniform_int_distribution<int> distr(1, 10);
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			
			int r = distr(generator);
			switch (r) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				rooms[y][x] = new Room("Hallway", "You are in a hallway.", MakeItem());
				break;
			case 8:
				rooms[y][x] = new Room("Armoury", "You are in a room with racks of old weapons and stands of old armor.", MakeItem());
				break;
			case 9:
				rooms[y][x] = new Room("Tomb", "You are in a burial chamber.", MakeItem());
				break;
			case 10:
				rooms[y][x] = new Room("Treasure Room", "You are in a room filled with various treasure.", MakeItem());
				break;
			}
			//std::cout << "\t" << r << ": " << rooms[y][x]->GetName() << " | " << ((rooms[y][x]->GetItem() != nullptr) ? rooms[y][x]->GetItem()->GetName() : "None") << std::endl;
		}
	}
	rooms[2][2] = new Room("Dungeon Entrance", "You are at the dungeon entrance.", nullptr);
}

Item* Game::MakeItem() {
	Item* item{};
	std::random_device rand;
	std::mt19937 generator(rand());
	std::uniform_int_distribution<int> distr(1, 2);
	int r = distr(generator);
	if (r == 1) {
		std::random_device rand;
		std::mt19937 generator(rand());
		std::uniform_int_distribution<int> distr(1, 6);
		int b = distr(generator);
		switch (b) {
		case 0:
			
		case 1:
			
		case 2:
			
		case 3:
			
		case 4:
			
		case 5:
			item = new Consumable("Health Potion", "This is a health potion.", 3);
		}
		return item;
	}
	else return nullptr;
}