#pragma once
#include "Constants.h"
#include "Player.h"
#include "Room.h"

#include <random>

class Game
{
public:
	Game();
	~Game();

	void Run();

	void DisplayValidDirections(int x, int y);

	//void Move();

	//void Look();

	//void Use();

	//void Help();

	//void FindSpell();

	//void CastSpell();

	//void Spells();

	//void Quit();

	void MakeRooms(std::mt19937& gen);

	Item* MakeItem(std::mt19937 &gen);

	Spell* GenerateSpell(std::mt19937& gen);
private:
	Room* rooms[MAP_HEIGHT][MAP_WIDTH];
	Player* _player;
};

