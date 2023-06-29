#include "Item.h"
#include <string>

Item::Item(std::string n, int h, int a, int d)
{
	name = n;
	health = h;
	attack = a;
	defense = d;
}