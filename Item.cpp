#include "Item.h"

Item::Item() {}

Item::Item(String name, String description) : _name{ name }, _description{ description } {}

Item::~Item() {}

void Item::Description() const {
	std::cout << "\t\t" << _description << std::endl;
}

void Item::Use() {

}

String Item::GetName() {
	return _name;
}
