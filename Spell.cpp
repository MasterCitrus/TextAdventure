#include "Spell.h"

Spell::Spell() : _damage { 0 } {}

Spell::Spell(String name, int damage) : _name{ name }, _damage{damage} {}

Spell::~Spell() {}

static bool Compare(Spell a, Spell b) {
	return false;
}