#include "Consumable.h"

Consumable::Consumable() : Item(), _uses{0} {}

Consumable::Consumable(String name, String description, String effect, int uses) : Item(name, description), _uses{ uses }, _effect{ effect } {}

Consumable::~Consumable() {}

void Consumable::Use() {
	if (_uses > 0) {
		_uses--;
		std::cout << "\n\t\tYou have used the " << _name << ". It has " << _uses << " uses left." << std::endl;
		std::cout << "\t\t" << _effect << '\n';
		if (_uses == 0) _description = ((&_name.ToLower().CharacterAt(0) != "a" || &_name.ToLower().CharacterAt(0) != "e" || &_name.ToLower().CharacterAt(0) != "i" || &_name.ToLower().CharacterAt(0) != "o" || &_name.ToLower().CharacterAt(0) != "u") ? (String)"This is a " : (String)"This is an ") + _name + (String)". It is empty.";
	}
	else {
		std::cout << "\n\t\tIt cannot be used anymore.\n";
	}
}
