#include "Spell.h"

Spell::Spell() : _damage { 0 } {}

Spell::Spell(String name, int damage) : _name{ name }, _damage{damage} {}

Spell::~Spell() {}

void Spell::Cast() const {
	std::cout << "\n\t\tYou have casted " << _name << ". It does " << _damage << " damage.\n";
}

String Spell::GetName()
{
	return _name;
}

int Spell::GetDamage()
{
	return _damage;
}

bool Spell::Compare(Spell* a, Spell* b) {
	return a->GetName() < b->GetName();
}