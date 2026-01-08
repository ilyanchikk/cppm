#include <iostream>
#include <Windows.h>

void calc(int* arr_ptr, int in);
void print(int* arr_ptr, int in);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int in{};
	std::cout << "Введите количество чисел Фибоначчи: ";
	std::cin >> in;
	int* arr_ptr = new int [in] {0,1};
	calc( arr_ptr, in);
	print(arr_ptr, in);
	delete[] arr_ptr;
	return EXIT_SUCCESS;
}

void calc(int* arr_ptr, int in) {
	for (int i = 0; i < in; i++) {
		arr_ptr[i + 2] = arr_ptr[i] + arr_ptr[i + 1];
	}
}
void print(int* arr_ptr, int in) {
	for (int i = 0; i < in; i++) {
		std::cout << arr_ptr[i] << std::endl;
	}
}