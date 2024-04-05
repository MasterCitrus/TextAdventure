#include "Game.h"

int main() {
	Game game;
	game.Run();
	
	system("cls");
	std::cout << "\n\n\t\t>> GOODBYE <<";
	std::cout << std::endl << std::endl << "\t\tPress 'Enter' to exit.";
	
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}