#pragma once
#include "Spell.h"
#include "String.h"

#include <map>

class Player
{
public:
	Player();
	~Player();

	bool FindSpell(String spell);
private:
	std::map<String, Spell> spellList;
};

