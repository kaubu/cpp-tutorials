#include <array>
#include <iostream>

namespace rpg
{
	enum Item
	{
		healthPotion,
		torch,
		arrow
	};
}

int countTotalItems(std::array<int, 3> &array)
{
	int amount{};
	for (int i : array)
	{
		amount += i;
	}
	return amount;
}

int main()
{
	std::array<int, 3> items{ 2, 5, 10 };
	int itemCount{ countTotalItems(items) };

	std::cout << "The player has " << itemCount << " items.\n";
	std::cout << "The player has " << items[rpg::torch] << " torches.\n";
}