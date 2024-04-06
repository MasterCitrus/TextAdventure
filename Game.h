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

	//Sort input
	void HandleInput(String input);

	void DisplayValidDirections(Vec2 pos);

	//Command functions
	void Move(String direction, Vec2 pos);

	void Look(Vec2 pos);

	void Use(String item, Vec2 pos);

	void Help();

	void FindSpell(String spell);

	void CastSpell(String spell);

	void Spells();

	void Quit();

	void Invalid(Vec2 pos);
	//Command functions

	void MakeRooms(std::mt19937& gen);

	Item* MakeItem(std::mt19937 &gen);

	Spell* GenerateSpell(std::mt19937& gen);
private:
	Player* _player;
	Room* rooms[MAP_HEIGHT][MAP_WIDTH];
	bool _quit;
};

