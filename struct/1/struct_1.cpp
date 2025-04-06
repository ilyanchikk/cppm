#include <iostream>
#include <Windows.h>
#include <string>

enum month {
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	June,
	Juli,
	Aug,
	Sep,
	Okt,
	Nov,
	Dec
};
int main() {
	system("chcp 1251")
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number{};
	do {
		std::cout << "Введите номер месяца,(для выхода введите 0) : ";
		std::cin >> number;
		std::cout << std::endl;
		if (number < 0 || number > 12) {
			std::cout << "Введен некорретный месяц." << std::endl;
		}
		else if (number == 0) {
			std::cout << "До свидания." << std::endl;
			break;
		}
		else {
			month numb = static_cast<month>(number);
			switch (numb) {
			case Jan: std::cout << "Январь" << std::endl; break;
				case Feb: std::cout << "Февраль" << std::endl; break;
				case Mar: std::cout << "Март" << std::endl; break;
				case Apr: std::cout << "Апрель" << std::endl; break;
				case May: std::cout << "Май" << std::endl; break;
				case June: std::cout << "Июнь" << std::endl; break;
				case Juli: std::cout << "Июль" << std::endl; break;
				case Aug: std::cout << "Август" << std::endl; break;
				case Sep: std::cout << "Сентябрь" << std::endl; break;
				case Okt: std::cout << "Октябрь" << std::endl; break;
				case Nov: std::cout << "Ноябрь" << std::endl; break;
				case Dec: std::cout << "Декабрь" << std::endl; break;
				}
		}
	}
	while (number != 0);
	return 0;
}
