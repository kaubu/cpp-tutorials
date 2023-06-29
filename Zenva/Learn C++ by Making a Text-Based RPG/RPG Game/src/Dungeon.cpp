#include "Dungeon.h"
#include "GameCharacter.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

Dungeon::Dungeon(Player p)
{
	player = p;
}

void Dungeon::printActions(int numActions, std::string actions[])
{
	std::cout << "Choose an action:\n";
	for (int i = 0; i < numActions; i++)
	{
		std::cout << actions[i] << '\n';
	}
	std::cout << ">> ";
}

void Dungeon::handleFightActions(GameCharacter *enemy)
{
	std::string actions[]
	{
		"a. Attack",
		"b. Retreat"
	};

	while (true)
	{
		printActions(2, actions);
		std::string input;
		std::cin >> input;

		// Handle player actions
		if (input == "a")
		{
			int damage = enemy->takeDamage(player.attack);
			std::cout << "Your attack does " << damage << " damage.\n";
		}
		else if (input == "b")
		{
			player.changeRooms(player.previousRoom);
			enterRoom(player.currentRoom);
			return;
		}
		else
		{
			std::cout << "Incorrect choice.\n";
		}

		// Check if enemy is dead
		if (enemy->isDead())
		{
			std::cout << "You win! You have defeated the " << enemy->name << '\n';
			player.increaseStats(10, 5, 5);
			player.currentRoom->clearEnemies();
			return;
		}

		// Handle enemy actions
		int damage = player.takeDamage(enemy->attack);
		std::cout << enemy->name << "'s attack does " << damage << " damage.\n";
		std::cout << "You now have " << player.currentHealth << " health.\n";

		if (player.isDead())
		{
			return;
		}
	}
}

void Dungeon::handleRoomWithEnemy(Room *room)
{
	GameCharacter enemy = room->enemies.front();
	std::cout << "You enter the room and see a " << enemy.name << ".\n";
	std::string actions[]
	{
		"a. Fight the " + enemy.name,
		"b. Go back to previous room"
	};

	while (true)
	{
		printActions(2, actions);
		std::string input;
		std::cin >> input;

		if (input == "a")
		{
			handleFightActions(&enemy);
			return;
		}
		else if (input == "b")
		{
			player.changeRooms(player.previousRoom);
			enterRoom(player.currentRoom);
			return;
		}
		else
		{
			std::cout << "Incorrect choice.\n";
		}
	}
}

void Dungeon::handleLootActions(Room *room)
{
	Item item = room->items.front();
	size_t size = room->items.size();
	player.lootRoom(room);
	room->clearLoot();

	for (size_t i = 0; i < size; i++)
	{
		std::cout << "You've opened the chest and found a " << item.name << ".\n"; // item.name incorrect
		std::cout << "Your health is now " << player.currentHealth << ", your attack is now " << player.attack << ", and your defense is now " << player.defense << '\n';
	}
}

void Dungeon::handleRoomWithChest(Room *room)
{
	std::cout << "You enter the room and see a large chest in the middle.\n";
	std::string actions[]
	{
		"a. Loot the chest",
		"b. Move to another room"
	};

	while (true)
	{
		printActions(2, actions);
		std::string input;
		std::cin >> input;

		if (input == "a")
		{
			handleLootActions(room);
			return;
		}
		else if (input == "b")
		{
			return;
		}
		else
		{
			std::cout << "Incorrect choice.\n";
		}
	}
}

void Dungeon::handleEmptyRoom(Room *room)
{
	std::cout << "You enter the room but it is empty.\n";
	std::string actions[]{
		"a. Move to another room"
	};

	while (true)
	{
		printActions(1, actions);
		std::string input;
		std::cin >> input;

		if (input == "a")
		{
			return;
		}
		else
		{
			std::cout << "Incorrect choice.\n";
		}
	}
}

void Dungeon::enterRoom(Room *room)
{
	if (room->enemies.size() != 0)
	{
		handleRoomWithEnemy(room);
	}
	else if (room->items.size() != 0)
	{
		handleRoomWithChest(room);
	}
	else
	{
		handleEmptyRoom(room);
	}
}

void Dungeon::handleMovementActions(Room *room)
{
	while (true)
	{
		if (room->pos == 0)
		{
			std::string actions[]
			{
				"a. Move right",
				"b. Move down"
			};
			printActions(2, actions);
			std::string input;
			std::cin >> input;

			if (input == "a")
			{
				player.changeRooms(&rooms[1]);
				return;
			}
			else if (input == "b")
			{
				player.changeRooms(&rooms[2]);
				return;
			}
			else
			{
				std::cout << "Incorrect choice.\n";
			}
		}
		else if (room->pos == 1)
		{
			std::string actions[]
			{
				"a. Move left"
			};
			printActions(1, actions);
			std::string input;
			std::cin >> input;

			if (input == "a")
			{
				player.changeRooms(&rooms[0]);
				return;
			}
			else
			{
				std::cout << "Incorrect choice.\n";
			}
		}
		else if (room->pos == 2)
		{
			std::string actions[]
			{
				"a. Move up",
				"b. Move right"
			};
			printActions(2, actions);
			std::string input;
			std::cin >> input;

			if (input == "a")
			{
				player.changeRooms(&rooms[0]);
				return;
			}
			else if (input == "b")
			{
				player.changeRooms(&rooms[3]);
				return;
			}
			else
			{
				std::cout << "Incorrect choice.\n";
			}
		}
		else
		{
			std::string actions[]
			{
				"a. Move left"
			};
			printActions(1, actions);
			std::string input;
			std::cin >> input;

			if (input == "a")
			{
				player.changeRooms(&rooms[2]);
				return;
			}
			else
			{
				std::cout << "Incorrect choice.\n";
			}
		}
	}
}

int Dungeon::performEndGameLogic()
{
	std::string actions[]
	{
		"a. Yes",
		"b. No"
	};

	while (true)
	{
		printActions(2, actions);
		std::string input;
		std::cin >> input;

		if (input == "a")
		{
			return 1;
		}
		else if (input == "b")
		{
			return 0;
		}
		else
		{
			std::cout << "Incorrect choice.\n";
		}
	}
}

int Dungeon::runDungeon()
{
	std::cout << "Welcome to the dungeon! Inside you will find treasure, but also enemies. Enter at your own peril!\n";

	player.previousRoom = &rooms[0];
	player.currentRoom = &rooms[0];

	while (true)
	{
		enterRoom(player.currentRoom);
		
		if (player.isDead())
		{
			std::cout << "Game over! Try again?\n";
			return performEndGameLogic();
		}
		else
		{
			if (player.currentRoom->isExit)
			{
				if (player.currentRoom->enemies.size() == 0)
				{
					std::cout << "You win! Play again?\n";
					return performEndGameLogic();
				}
			}
		}
		
		handleMovementActions(player.currentRoom);
	}
}