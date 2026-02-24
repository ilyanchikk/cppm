#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <set>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size{ };

	std::cout << "Введите количество элементов: ";
	std::cin >> size;
	std::cout << std::endl;
	
	std::set<int, std::greater<int>> un_num;

	std::cout << "Введите элементы: " << std::endl;
	for (int i = 0; i < size; i++) {
		int tmp{};
		std::cin >> tmp;
		un_num.insert(tmp);
	}

	std::cout << "[OUT]: " << std::endl;
	for (int n : un_num) {
		std::cout << n  << std::endl;
	}

	return 0;
}
