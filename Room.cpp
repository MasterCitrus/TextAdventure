#include "Room.h"

Room::Room() : _item{nullptr} {}

Room::Room(String name, String description, Item* item) : _name{ name }, _description { description }, _item{ item } {}

Room::~Room() {}

void Room::Description() const {
	std::cout << "\t\t" << _description << std::endl;
}

String Room::GetName() {
	return _name;
}

Item* Room::GetItem() {
	if (_item != nullptr) return _item;
	return nullptr;
}