#pragma once
#include "String.h"

class Spell
{
public:
	Spell();
	Spell(String name, int damage);
	~Spell();

	static bool Compare(Spell a, Spell b);
private:
	String _name;
	int _damage;
};

