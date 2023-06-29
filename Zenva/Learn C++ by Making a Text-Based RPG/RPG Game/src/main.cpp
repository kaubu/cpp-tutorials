#include "Dungeon.h"
#include "Player.h"
#include "GameCharacter.h"
#include "Item.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

Dungeon dungeonSetup()
{
	// Set up the player
	std::cout << "Welcome to a generic RPG game! What is your name?\n>> ";
	std::string playerName;
	std::cin >> playerName;
	Player player{ Player(playerName, 100, 20, 10) };

	// Set up the first room
	Room firstRoom{ Room(0, false, std::vector<Item>(), std::vector<GameCharacter>()) };

	// Set up the second room
	Item sword{ Item("Sword", 0, 20, 0) };
	std::vector<Item> secondRoomItems;
	secondRoomItems.push_back(sword);
	Room secondRoom{ Room(1, false, secondRoomItems, std::vector<GameCharacter>()) };

	// Set up the third room
	GameCharacter firstEnemy{ GameCharacter("Imp", 50, 15, 5) };
	std::vector<GameCharacter> thirdRoomEnemies;
	thirdRoomEnemies.push_back(firstEnemy);
	Room thirdRoom{ Room(2, false, std::vector<Item>(), thirdRoomEnemies) };

	// Set up the fourth room
	GameCharacter secondEnemy{ GameCharacter("Minotaur", 100, 20, 10) };
	std::vector<GameCharacter> fourthRoomEnemies;
	fourthRoomEnemies.push_back(secondEnemy);
	Room fourthRoom{ Room(3, true, std::vector<Item>(), fourthRoomEnemies) };

	// Set up the dungeon
	Dungeon dungeon{ Dungeon(player) };
	dungeon.rooms[0] = firstRoom;
	dungeon.rooms[1] = secondRoom;
	dungeon.rooms[2] = thirdRoom;
	dungeon.rooms[3] = fourthRoom;

	return dungeon;
}

int main()
{
	while (true)
	{
		Dungeon dungeon{ dungeonSetup() };

		int result{ dungeon.runDungeon() };
		if (result == 0)
		{
			break;
		}
	}

	std::cout << "Goodbye!\n";
	return 0;
}