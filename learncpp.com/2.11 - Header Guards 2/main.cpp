#include "square.h"
#include <iostream>

int main()
{
	std::cout << "a square has " << getSquareSides() << " sides\n";
	std::cout << "a square has a length of 5 has perimeter length " << getSquarePerimeter(5) << '\n';
	
	return 0;
}
