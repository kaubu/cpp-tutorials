#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
	std::string name;
	int health, attack, defense;
	Item(std::string, int, int, int);
};

#endif // ITEM_H