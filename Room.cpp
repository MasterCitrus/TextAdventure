#include "Room.h"

Room::Room() : item{nullptr} {}

Room::Room(String descritpion, Item* item) {}

Room::~Room() {}

void Room::Description() const {
	std::cout << _description << std::endl;
}