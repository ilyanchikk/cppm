#include <iostream>
#include <Windows.h>
#include <string>

struct account {
	int number;
	std::string name;
	double bank;
};
void change_balance(account* p_acc);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	account People;
	account* p_acc = &People;
	std::cout << "������� ����� �����: ";
	std::cin >> People.number;
	std::cout << std::endl;
	std::cout << "������� ��� ���������: ";
	std::cin >> People.name;
	std::cout << std::endl;
	std::cout << "������� ������: ";
	std::cin >> People.bank;
	std::cout << std::endl;
	change_balance(p_acc);
	std::cout << "����� �����: " << People.number << ", " << "��� ���������: " << People.name << ", " << "������ �����: " << People.bank << std::endl;
	return 0;
}

void change_balance(account* p_acc) {
	std::cout << "������� ����� ������: ";
	std::cin >> p_acc->bank;
}