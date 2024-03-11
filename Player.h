#pragma once
#include "Spell.h"
#include "String.h"

#include <vector>
#include <algorithm>

class Player
{
public:
	Player();
	~Player();

	bool FindSpell(String& spell);

	Spell* CastSpell(String& spell);

	std::vector<Spell*> GetSpellList();

	void SpellList();

	void AddSpell(Spell* spell);
private:
	std::vector<Spell*> spellList;
};

