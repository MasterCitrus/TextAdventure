#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(String name, String description);
	~Weapon();

	void Use() override;
};

