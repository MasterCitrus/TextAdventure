#include "Room.h"

Room::Room() : _item{nullptr} {}

Room::Room(String description, Item* item) : _description{ description }, _item{item} {}

Room::~Room() {}

void Room::Description() const {
	std::cout << "\t\t" << _description << std::endl;
	if (_item == nullptr) std::cout << "\t\tYou see nothing of value here.\n";
	else {
		_item->Description();
	}
}