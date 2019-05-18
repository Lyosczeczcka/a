/*
Написать программу, решающую игру-головоломку. Предусмотреть два режима решения: непрерывный
(с некоторой задержкой визуализации) и пошаговый (по нажатию любой клавиши). В программе использовать стек.

Реализовать шаблонный класс - универсальную объектную коллекцию
	Обобщенное программирование
	Использовать в программе в каком то частном применении с явным указаним типов данных, с кот. он работает.
	В пояснительной записке на уровне листинга продемонстрировать использование шаблона с отличным параметром
	Внутри классов не должно быть никакой работы с интерфейсом, т.к. может от программы к программе меняться.
	??Может использовать std::swap в качестве шаблонного класса??
Перегрузить оператор побитового сдвига для записи и чтения коллекции в поток
Создать коллекцию для простого типа данных и для любого составного типа данных (класса)
	Коллекция ключ-значение (с уникальными и неуникальными ключами)
	Стек на основе списка или расширяющегося массива
	Очередь с или без приоритета
Обеспечить сохранение и восстановление состояния программы из файловой системы:
	Первый запуск - запрос логина, сделать рейтинг игроков.
*/
#include <iostream>
#include <ctime>
#include <windows.h> //Для system("cls")
#include <conio.h>
using namespace std;


int game();
int zeroSearch();
int menu();
int main()
{
	menu();
	return 0;
}
int menu()
{
	unsigned int menuChoose;
	cout << "Welcome to The New Puzzle game! \n1. I want to play!\n2. Show me solutions\n3. Exit" << endl;
	cin >> menuChoose;
	switch (menuChoose)
	{
	case 1:
		game();
	case 2:
		//to solutions
		break;
	case 3:
		return 0;
		break;
	}
	return 0;
}
int game()
{
	srand(time(NULL));
	const int arraySize = 4;
	int numbers[16], array[arraySize][arraySize];
	int izero, jzero;
	system("cls");
	for (int i = 0; i < 16; i++) //Заполнил массив числами по порядку
	{
		numbers[i] = i;
	}
	/*
	for (int i = 0; i < 16; i++) //Вывел для проверки
	{
		cout << numbers[i] << "\t";
	} cout << endl; */
	for (int i = 0; i < 16; i++) //Перемешал элементы в рандомном порядке
	{
		int j = rand() % 16;
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}
	/*
	for (int i = 0; i < 16; i++) //Вывел для проверки
	{
		cout << numbers[i] << "\t";
	} cout << endl; */
	for (int i = 0, k = 0; i < arraySize; i++) //Заполнил двумерный массив элементами одномерного
	{
		for (int j = 0; j < arraySize; j++)
		{
			array[i][j] = numbers[i + j + k];
		}
		k = k + 3;
	} cout << endl;
	for (int i = 0; i < arraySize; i++) //Вывел массив
	{
		for (int j = 0; j < arraySize; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < arraySize; i++) //Поиск элемента со значением 0.
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (array[i][j] == 0)
			{
				izero = i;
				jzero = j;
			}
		}
	}

	while (true)
	{
		int click;
		click = _getch(); //Проверка нажатия клавиши
		if (click == 72) //Стрелка вверх
		{
			if (izero > 0)
			{
				system("cls");
				std::swap(array[izero][jzero], array[izero - 1][jzero]);
				for (int i = 0; i < arraySize; i++)
				{
					for (int j = 0; j < arraySize; j++)
					{
						std::cout << array[i][j] << "\t";
						if (array[i][j] == 0)
						{
							izero = i;
							jzero = j;
						}
					}
					std::cout << std::endl;
				}

			}
			else { std::cout << "No way!" << std::endl; }
		}

		if (click == 80) //Стрелка вниз
		{
			if (izero < 3)
			{
				system("cls");
				std::swap(array[izero][jzero], array[izero + 1][jzero]);
				for (int i = 0; i < arraySize; i++)
				{
					for (int j = 0; j < arraySize; j++)
					{
						std::cout << array[i][j] << "\t";
						if (array[i][j] == 0)
						{
							izero = i;
							jzero = j;
						}

					}
					std::cout << std::endl;
				}


			}
			else { std::cout << "No way!" << std::endl; }

		}
		if (click == 75) //Стрелка влево
		{
			if (jzero > 0)
			{
				system("cls");
				std::swap(array[izero][jzero], array[izero][jzero - 1]);
				for (int i = 0; i < arraySize; i++)
				{
					for (int j = 0; j < arraySize; j++)
					{
						std::cout << array[i][j] << "\t";
						if (array[i][j] == 0)
						{
							izero = i;
							jzero = j;
						}

					}
					std::cout << std::endl;
				}

			}
			else { std::cout << "No way!" << std::endl; }
		}

		if (click == 77) //Стрелка вправо
		{
			if (jzero < 3)	{
				system("cls");
				std::swap(array[izero][jzero], array[izero][jzero + 1]);
				for (int i = 0; i < arraySize; i++) {
					for (int j = 0; j < arraySize; j++) {
						std::cout << array[i][j] << "\t";
						if (array[i][j] == 0)
						{
							izero = i;
							jzero = j;
						}

					}  std::cout << std::endl;
				}
			} else { std::cout << "No way!" << std::endl; }
		}
		if (click == 27) { break; } //Esc
	}
	return 0;
}
int zeroSearch(int arraySize, int array[], int& izero, int &jzero)
{
	
	return 0;
}
