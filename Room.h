#pragma once
#include "Item.h"

class Room
{
public:
	Room();
	Room(String name, String Description, Item* item);
	~Room();

	void Description() const;

	String GetName() const;

	Item* GetItem();

private:
	String _description;
	String _name;
	Item* _item;
};

