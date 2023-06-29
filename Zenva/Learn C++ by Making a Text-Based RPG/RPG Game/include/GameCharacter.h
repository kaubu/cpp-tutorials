#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>

class GameCharacter
{
public:
	std::string name;
	int maxHealth, currentHealth, attack, defense;
	GameCharacter(std::string, int, int, int);
	int takeDamage(int);
	bool isDead();
};

#endif // GAME_CHARACTER_H