#pragma once
#include "Constants.h"
#include "Player.h"
#include "Room.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void DisplayValidDirections(int x, int y);

	void MakeRooms();

	Item* MakeItem();

	Spell* GenerateSpell();
private:
	Room* rooms[MAP_HEIGHT][MAP_WIDTH];
	Player* _player;
};

