#include "constants.h"
#include <iostream>

int getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	int height{};
	std::cin >> height;
	return height;
}

double calculateHeight(int seconds)
{
	double distanceFallen{constants::gravity * seconds * seconds / 2};
	return distanceFallen;
}

void displayHeight(int initialHeight, int seconds)
{
	double currentHeight{ initialHeight - calculateHeight(seconds) };
	if (currentHeight <= 0)
	{
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
	}
	else
	{
		std::cout << "At " << seconds << " seconds, the ball is at height: " << currentHeight << " meters\n";
	}
}

int main()
{
	int initialHeight{ getInitialHeight() };

	displayHeight(initialHeight, 0);
	displayHeight(initialHeight, 1);
	displayHeight(initialHeight, 2);
	displayHeight(initialHeight, 3);
	displayHeight(initialHeight, 4);
	displayHeight(initialHeight, 5);

	return 0;
}