#pragma once
#include "String.h"

class Item
{
public:
	Item();
	Item(String name, String description);
	virtual ~Item();

	void Description() const;
	virtual void Use();

	String GetName();
protected:
	String _description;
	String _name;
};

