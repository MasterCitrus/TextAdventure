#include "Consumable.h"

Consumable::Consumable() : Item(), _uses{0} {}

Consumable::Consumable(String name, String description, int uses) : Item(name, description), _uses{uses} {}

Consumable::~Consumable() {}

void Consumable::Use() {
	if (_uses > 0) {
		_uses--;
		std::cout << "\t\tYou have used the " << _name << ". It has " << _uses << " uses left." << std::endl;
		if (_uses == 0) _description = ((&_name.ToLower().CharacterAt(0) != "a" || "e" || "i" || "o" || "u") ? (String)"This is a " : (String)"This is an ") + _name + (String)". It is empty.";
	}
	else {
		std::cout << "\t\tIt cannot be used anymore.\n";
	}
}
