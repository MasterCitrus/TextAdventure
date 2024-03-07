#pragma once
#include "Item.h"
#include "String.h"

class Room
{
public:
	Room();
	Room(String Description, Item* item);
	~Room();

	void Description() const;
private:
	String _description;
	Item* _item;
};

