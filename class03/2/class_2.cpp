#include <iostream>
#include <Windows.h>
#include <string>

char change{};

class Count {
private:
	 int num {};
public:
	Count(int num) {
		this->num = num;
	}
	Count() {
		this->num = 1;
	}
	void plus() { ++num; }
	void minus() { --num; }
	void view() { std::cout << "Текущее показание счетчика: " << num << std::endl; }
	void play() {
		do {
			std::cout << "Введите команду ('+', '-', '=' или 'x'):";
			std::cin >> change;
			switch (change) {
			case '+': plus(); break;
			case '-': minus(); break;
			case 'x': break;
			case '=': view(); break;
			}
		} while (change != 'x');
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string countS;
	int countStart {};

		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> countS;
		if (countS == "да") {
			std::cout << "Введите начальное значение счетчика: ";
			std::cin >> countStart;
			Count count(countStart);
			count.play();
			std::cout << "До свидания" << std::endl;
		}
		else if (countS == "нет") {
			Count count;
			count.play();
			std::cout << "До свидания" << std::endl;
		}
		else std::cout << "Введено недопустимое значение." << std::endl;
	
	return EXIT_SUCCESS;
}
