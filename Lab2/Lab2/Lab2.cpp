#include <pch.h>
#include <iostream>

int main()
{
	int number1, number2, number3, number4, number5;
	int f1, f2, f3, f4, f5;
	int c;

	std::cout << "Enter 5 nor." << std::endl;
	std::cin >> number1;
	std::cin >> number2;
	std::cin >> number3;
	std::cin >> number4;
	std::cin >> number5;
	f1 = number1 * number1;
	f2 = number2 * number2;
	f3 = number3 * number3;
	f4 = number4 * number4;
	f5 = number5 * number5;
	c = f1 * f3 - f2 / f4 + f4 * (f5 - f1) - f2;
	std::cout << c << std::endl;

}
