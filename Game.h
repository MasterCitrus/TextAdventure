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

	void MakeRooms();

	Item* MakeItem();
private:
	Room* rooms[MAP_HEIGHT][MAP_WIDTH];
	Player* _player;
};

