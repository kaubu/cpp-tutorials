#include <iostream>

int main()
{
	//bool isGameRunning{ true };
	int xPos{ 0 };
	int endPos{ 10 };

	/*while (isGameRunning)
	{
		xPos += 1;
		std::cout << xPos << '\n';

		if (xPos >= endPos)
		{
			isGameRunning = false;
		}
	}*/

	while (true)
	{
		xPos += 1;
		std::cout << xPos << '\n';

		if (xPos >= endPos)
		{
			break;
		}
	}

	std::cout << "Game over!\n";

	return 0;
}
