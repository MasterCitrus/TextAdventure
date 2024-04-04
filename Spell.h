#pragma once
#include "String.h"

class Spell
{
public:
	Spell();
	Spell(String name, int damage);
	~Spell();

	void Cast() const;

	String GetName();

	int GetDamage();

	static bool Compare(Spell* a, Spell* b);
private:
	String _name;
	int _damage;
};

