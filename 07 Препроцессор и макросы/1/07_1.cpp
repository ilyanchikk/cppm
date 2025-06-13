#include <iostream>
#include <Windows.h>

void add(int num1, int num2);

#define MODE 1 
#ifdef MODE 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	int num1, num2{};
	std::cout << "Работаю в боевом режиме" << std::endl;
	std::cout << "Введите первое число: " << std::endl;
	std::cin >> num1;
	std::cout << std::endl;
	std::cout << "Введите второе число: " << std::endl;
	std::cin >> num2;
	std::cout << std::endl;
	add(num1, num2);
	return 0;
#else 
	std::cout << "Неизвестный режим, завершение работы." << std::endl;
#endif
}
#else
#error Директива MODE не определена, определите MODE
#endif

void add(int num1, int num2) {
	std::cout << "Результат сложения: " << num1 + num2 << std::endl;
}