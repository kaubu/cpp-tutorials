#include <iostream>

int main()
{
	const int n{ 3 };
	std::string inventory[n];
	inventory[0] = "Sword";
	inventory[1] = "Shield";
	inventory[2] = "Bow";

	for (int i = 0; i < n; i++)
	{
		std::cout << inventory[i] << '\n';
	}
}