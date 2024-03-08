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

	void AddSpell(Spell* spell);
private:
	std::map<String, Spell*> spellList;
};

