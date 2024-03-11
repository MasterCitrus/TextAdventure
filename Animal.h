#pragma once
#include "Item.h"

class Animal : public Item
{
public:
	Animal();
	Animal(String name, String description, String action);
	~Animal();

	void Use() override;
private:
	String _action;
};

