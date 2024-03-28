#include "iter.hpp"
#include <iostream>

void printNumber(int n)
{
	std::cout << n << std::endl;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	iter(arr, 5, printNumber);

	return 0;
}
