#include <iostream>
#include <Windows.h>
#include <string>
#include "count.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string countS;
	int countStart{};
	char change{};

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> countS;
	if (countS == "да") {
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> countStart;
		Count count(countStart);
		do {
			std::cout << "Введите команду ('+', '-', '=' или 'x'):";
			std::cin >> change;
			switch (change) {
			case '+': count.plus(); break;
			case '-': count.minus(); break;
			case 'x': break;
			case '=': std::cout << "Текущее показание счетчика: " << count.getnum() << std::endl; break;
			}
		} while (change != 'x');
		std::cout << "До свидания" << std::endl;
	}
	else if (countS == "нет") {
		Count count;
		do {
			std::cout << "Введите команду ('+', '-', '=' или 'x'):";
			std::cin >> change;
			switch (change) {
			case '+': count.plus(); break;
			case '-': count.minus(); break;
			case 'x': break;
			case '=': std::cout << "Текущее показание счетчика: " << count.getnum() << std::endl; break;
			}
		} while (change != 'x');
		std::cout << "До свидания" << std::endl;
	}
	else std::cout << "Введено недопустимое значение." << std::endl;

	return EXIT_SUCCESS;
}