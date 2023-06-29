#include "GameCharacter.h"
#include <string>

GameCharacter::GameCharacter(std::string n, int h, int a, int d)
{
	name = n;
	maxHealth = h;
	currentHealth = h;
	attack = a;
	defense = d;
}

int GameCharacter::takeDamage(int amount)
{
	int damage = amount - defense;

	if (damage < 0)
	{
		damage = 0;
	}

	currentHealth -= damage;
	return damage;
}

bool GameCharacter::isDead()
{
	return currentHealth <= 0;
}