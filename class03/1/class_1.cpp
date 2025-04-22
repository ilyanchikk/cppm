
#include <iostream>
#include <Windows.h>
#include <string>

class Calculator {
private:
	double num1, num2;
public:
	Calculator(double num1, double num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	 double add() { return num1 + num2; }
	 double multiply() { return num1 * num2; }
	 double subtract_1_2() { return num2 - num1; }
	 double subtract_2_1() { return num1 - num2; }
	 double divide_1_2() { return num1 / num2; }
	 double divide_2_1() { return num2 / num1; }
	 bool set_num1(double num1) { 
		 this->num1 = num1; 
		 if (this->num1 != 0) { return true; } 
		 else { return false; }
	 }
	 bool set_num2(double num2) {
		 this->num2 = num2;
		 if (this->num2 != 0) { return true; }
		 else { return false; }
	 }
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num1{}, num2{};
	do {
		std::cout << "Введите первое число: ";
		std::cin >> num1;
		std::cout << std::endl;
		std::cout << "Введите второе число: ";
		std::cin >> num2;
		std::cout << std::endl;
		Calculator calc(num1, num2);
		if (calc.set_num1(num1) == true && calc.set_num2(num2) == true) {
			std::cout << "num1 + num2: " << calc.add() << std::endl;
			std::cout << "num1 * num2: " << calc.multiply() << std::endl;
			std::cout << "num2 - num1: " << calc.subtract_1_2() << std::endl;
			std::cout << "num1 - num2: " << calc.subtract_2_1() << std::endl;
			std::cout << "num1 / num2: " << calc.divide_1_2() << std::endl;
			std::cout << "num2 / num1: " << calc.divide_2_1() << std::endl;
		}
		else std::cout << "Введены недопустимые данные" << std::endl;
	} while ( 1 > 0 );

	return EXIT_SUCCESS;
}
