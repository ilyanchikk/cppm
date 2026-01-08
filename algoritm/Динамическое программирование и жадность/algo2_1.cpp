#include <iostream>
#include <Windows.h>

void calc(int in, long long a, long long b, long long c, int count);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int in{};
	long long a{ 0 };
	long long b{ 0 };
	long long c{ 1 };
	int count{ 0 };
	std::cout << "Введите количество чисел Фибоначчи: ";
	std::cin >> in;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	calc(in, a, b, c, count);

	return EXIT_SUCCESS;
}

void calc(int in, long long a, long long b, long long c,int count) {
	count++;
	b = c;
	c += a ;
	a = b; 
	std::cout << c << std::endl;
	if (in != count) { calc(in, a, b, c, count); }
}