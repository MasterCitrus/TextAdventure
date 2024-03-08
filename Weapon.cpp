#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(String name, String description) : Item(name, description) {}

Weapon::~Weapon() {}

void Weapon::Use() {
	std::cout << "\n\t\tThe weapon rejects you! You are not worthy.\n";
}