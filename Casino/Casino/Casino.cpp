
#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

int menu()
{
	int variant;
	std::cout << "1. Play! \n"
		      << "2. Score \n" << std::endl;
	return 0;
		      
}

int main()
{
	int loses, Try, wins, enter;
	char Exit;
	char again;
	int money = 1000;

	int variant = menu();
	std::cin >> variant;
	switch (variant)
	{
		case 1:
        do
		{

			int randomDigits = 0;
			srand(time(NULL));
			randomDigits = rand() % 3;
			std::cout << "Pick number (1;2) \nYour money: " << money << " \n";
			std::cin >> enter;

			if (randomDigits == enter)
			{
				money = money + 6000;
				std::cout << "Good! \nYour money: " << money << " \n Try again or exit? Y/N \n";

				std::cin >> again;
			}
			else
			{
				money = money - 100;
				std::cout << "No. \nYour money: " << money << " \n  Try again or exit? Y/N \n";

				std::cin >> again;
			}

		} while (again == 'y');
		break;

		case 2:
			std::cout << money;
			std::cout << "Exit? Y/N";
			std::cin >> Exit;
			while (Exit == 'y');
			{
				exit(EXIT_SUCCESS);
				break;
			}
	}

	return 0;
}


