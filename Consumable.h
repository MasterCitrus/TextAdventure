#pragma once
#include "Item.h"
#include "String.h"

class Consumable : public Item
{
public:
	Consumable();
	Consumable(String name, String description, String effect, int uses);
	~Consumable();

	void Use() override;

private:
	int _uses;
	String _effect;
};

