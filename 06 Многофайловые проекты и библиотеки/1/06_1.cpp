#include <iostream>
#include <string>
#include <Windows.h>
#include "Math.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num1, num2{};
	int operation{};
	while (operation != 6) {
	std::cout << "Введите первое число: ";
	std::cin >> num1;
	std::cout << std::endl;
	std::cout << "Введите второе число: ";
	std::cin >> num2;
	std::cout << std::endl;
	std::cout << "Выберите тип операции ( 1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 6 - выход) ";
	std::cin >> operation;
	std::cout << std::endl;
		switch (operation) {
		case 1: std::cout << "Результат cложения " << num1 << " и " << num2 << " = " << mat::sum(num1, num2) << std::endl; break;
		case 2: std::cout << "Результат вычитания " << num1 << " и " << num2 << " = " << mat::difference(num1, num2) << std::endl; break;
		case 3: std::cout << "Результат умножения " << num1 << " и " << num2 << " = " << mat::multiplication(num1, num2) << std::endl; break;
		case 4: std::cout << "Результат вычитания " << num1 << " и " << num2 << " = " << mat::division(num1, num2) << std::endl; break;
		case 5: std::cout << "Результат возведения в степень " << num1 << " и " << num2 << " = " << mat::exponent(num1, num2) << std::endl; break;
		case 6: std::cout << "Выход" << std::endl; break;
		default: std::cout << "Введено недопустимое значение" << std::endl; break;
		}
	}
	return 0;
}