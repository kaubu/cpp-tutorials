#include <iostream>

int takeDamage(int attack, int defence)
{
	int damage{ attack - defence };
	
	if (damage < 0)
	{
		damage = 0;
	}

	return damage;
}

int main()
{
	int damage{ takeDamage(1, 5) };
	std::cout << damage;

	return 0;
}
