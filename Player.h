#pragma once
#include "Spell.h"
#include "String.h"
#include "Vec2.h"

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

	void SetPos(Vec2 pos);

	Vec2 GetPos() const;
private:
	std::vector<Spell*> spellList;
	Vec2 playerPos;
};

