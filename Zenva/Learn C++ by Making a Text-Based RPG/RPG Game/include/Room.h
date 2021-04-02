#ifndef ROOM_H
#define ROOM_H

#include "GameCharacter.h"
#include "Item.h"
#include <vector>

class Room
{
public:
	int pos;
	bool isExit;
	std::vector<Item> items;
	std::vector<GameCharacter> enemies;
	Room(int=0, bool=false, std::vector<Item> = std::vector<Item>(), std::vector<GameCharacter> = std::vector<GameCharacter>());
	void clearLoot();
	void clearEnemies();
};

#endif // ROOM_H