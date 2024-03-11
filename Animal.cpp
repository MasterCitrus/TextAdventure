#include "Animal.h"

Animal::Animal() {}

Animal::Animal(String name, String description, String action) : Item(name, description), _action{action} {}

Animal::~Animal() {}

void Animal::Use() {
	std::cout << "\n\t\t" << _action << "\n";
}