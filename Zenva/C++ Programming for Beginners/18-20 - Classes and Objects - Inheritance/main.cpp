#include <iostream>
#include <string>
#include <vector>

class GameCharacter
{
public:
	int maxHealth, currentHealth, attack, defence;
	GameCharacter(int, int, int);
	void takeDamage(int);
};

GameCharacter::GameCharacter(int h, int a, int d)
{
	maxHealth = h;
	currentHealth = h;
	attack = a;
	defence = d;
}

void GameCharacter::takeDamage(int a)
{
	int damage = a - defence;
	if (damage < 0)
	{
		damage = 0;
	}

	currentHealth -= damage;
}

class Player : public GameCharacter
{
public:
	std::string name;
	std::vector<std::string> inventory;
	Player(std::string, int, int, int);
	void addItem(std::string);
};

Player::Player(std::string n, int h, int a, int d) :
	GameCharacter(h, a, d)
{
	name = n;
}

void Player::addItem(std::string i)
{
	inventory.push_back(i);
}

int main()
{
	GameCharacter gc{ GameCharacter(100, 20, 10) };
	std::cout << gc.currentHealth << '\n';
	gc.takeDamage(50);
	std::cout << gc.currentHealth;

	Player p{ Player("Adam", 120, 30, 20) };
	p.addItem("Boots");
	
	GameCharacter gcc{ GameCharacter(100, 20, 10) };

	return 0;
}