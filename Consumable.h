#pragma once
#include "Item.h"
#include "String.h"

class Consumable : public Item
{
public:
	Consumable();
	Consumable(String name, String description, int uses);
	~Consumable();

	void Use() override;

private:
	int _uses;
};

