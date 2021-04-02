#include "Room.h"
#include "GameCharacter.h"
#include "Item.h"
#include <vector>

Room::Room(int p, bool ie, std::vector<Item> is, std::vector<GameCharacter> gcs)
{
	pos = p;
	isExit = ie;
	items = is;
	enemies = gcs;
}

void Room::clearLoot()
{
	items.clear();
}

void Room::clearEnemies()
{
	enemies.clear();
}