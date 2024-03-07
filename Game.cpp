#include "Game.h"

Game::Game() {
	MakeRooms();
}

Game::~Game() {}

void Game::Run() {
	int playerPosX = 2;
	int playerPosY = 2;
	std::cout << "\t\tWELCOME TO THE DUNGEON." << std::endl << std::endl;
	std::cout << "\t\tPress 'Enter' to start.";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	while (true) {
		system("cls");
		std::cout << "\t\tPOS: " << playerPosX << " , " << playerPosY << "\n";
		rooms[playerPosY][playerPosX].Description();
		String input;
		std::cout << "\n\n\t\t>> ";
		input.ReadFromConsole();

		if (input == "move north" && playerPosY < MAP_HEIGHT - 1) playerPosY++;
		else if (input == "move south" && playerPosY > 0) playerPosY--;
		else if (input == "move east" && playerPosX > 0) playerPosX--;
		else if (input == "move west" && playerPosX < MAP_WIDTH - 1) playerPosX++;
		else if (input == "quit") break;
		else std::cout << std::endl << "\t\tInvalid Command!";

		std::cout << std::endl << std::endl << "\t\tPress 'Enter' to continue.";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
	}
}

void Game::MakeRooms() {
	std::cout << "Generating rooms...";
	Room entry = Room("\t\tYou are at the dungeon entrance.", nullptr);
	Room empty = Room("\t\tYou are in a very bare room.", nullptr);
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_HEIGHT; x++) {
			rooms[y][x] = empty;
		}
	}
	rooms[2][2] = entry;
}

//Item Game::MakeItem() {
//	return nullptr;
//}