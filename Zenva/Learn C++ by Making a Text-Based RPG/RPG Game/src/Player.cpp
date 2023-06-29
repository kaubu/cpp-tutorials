#include "Player.h"
#include "GameCharacter.h"
#include "Item.h"
#include "Room.h"
#include <string>
#include <vector>

Player::Player(std::string n, int h, int a, int d) : GameCharacter(n, h, a, d)
{
	Item dagger = Item("Dagger", 0, 5, 0);
	addItem(dagger);
}

void Player::addItem(Item item)
{
	inventory.push_back(item);
	increaseStats(item.health, item.attack, item.defense);
}

void Player::increaseStats(int h, int a, int d)
{
	maxHealth += h;
	currentHealth += h;
	attack += a;
	defense += d;
}

void Player::lootRoom(Room *room)
{
	std::vector<Item> items = room->items;
	for (size_t i = 0; i < items.size(); i++)
	{
		addItem(items[i]);
	}
}

void Player::changeRooms(Room *newRoom)
{
	previousRoom = currentRoom;
	currentRoom = newRoom;
}