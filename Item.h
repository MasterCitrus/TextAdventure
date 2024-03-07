#pragma once
#include "String.h"

class Item
{
public:
	Item();
	virtual ~Item();

	virtual void Description() const;
	virtual void Use();
private:

};

