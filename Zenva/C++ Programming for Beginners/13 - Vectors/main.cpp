#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("Sword");
	inventory.push_back("Shield");

	inventory.pop_back();
	inventory.size();
	inventory.front();
	inventory.back();
	inventory.clear();

	return 0;
}
