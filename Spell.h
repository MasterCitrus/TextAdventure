#pragma once
#include "String.h"

class Spell
{
public:
	Spell();
	~Spell();

	static bool Compare(Spell a, Spell b);
private:
	String _name;
	int _damage;
};

