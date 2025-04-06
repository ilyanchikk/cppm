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
	std::cout << "Введите номер счета: ";
	std::cin >> People.number;
	std::cout << std::endl;
	std::cout << "Введите имя владельца: ";
	std::cin >> People.name;
	std::cout << std::endl;
	std::cout << "Введите баланс: ";
	std::cin >> People.bank;
	std::cout << std::endl;
	change_balance(p_acc);
	std::cout << "Номер счета: " << People.number << ", " << "Имя Владельца: " << People.name << ", " << "Баланс счета: " << People.bank << std::endl;
	return 0;
}

void change_balance(account* p_acc) {
	std::cout << "Введите новый баланс: ";
	std::cin >> p_acc->bank;
}