#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(String name, String description, bool canUse) : Item(name, description), _canUse{canUse} {}

Weapon::~Weapon() {}

void Weapon::Use() {
	if (_canUse) std::cout << "\n\t\tThe weapon accepts you.\n";
	else std::cout << "\n\t\tThe weapon rejects you! You are not worthy.\n";
}