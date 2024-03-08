#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(String name, String description, bool canUse);
	~Weapon();

	void Use() override;
private:
	bool _canUse;
};

