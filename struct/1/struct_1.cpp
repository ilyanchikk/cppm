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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number{};
	do {
		std::cout << "������� ����� ������,(��� ������ ������� 0) : ";
		std::cin >> number;
		std::cout << std::endl;
		if (number < 0 || number > 12) {
			std::cout << "������ ����������� �����." << std::endl;
		}
		else if (number == 0) {
			std::cout << "�� ��������." << std::endl;
			break;
		}
		else {
			month numb = static_cast<month>(number);
			switch (numb) {
			case Jan: std::cout << "������" << std::endl; break;
				case Feb: std::cout << "�������" << std::endl; break;
				case Mar: std::cout << "����" << std::endl; break;
				case Apr: std::cout << "������" << std::endl; break;
				case May: std::cout << "���" << std::endl; break;
				case June: std::cout << "����" << std::endl; break;
				case Juli: std::cout << "����" << std::endl; break;
				case Aug: std::cout << "������" << std::endl; break;
				case Sep: std::cout << "��������" << std::endl; break;
				case Okt: std::cout << "�������" << std::endl; break;
				case Nov: std::cout << "������" << std::endl; break;
				case Dec: std::cout << "�������" << std::endl; break;
				}
		}
	}
	while (number != 0);
	return 0;
}
