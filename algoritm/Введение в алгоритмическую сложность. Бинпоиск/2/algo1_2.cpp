#include <iostream>
#include <Windows.h>
int sort(int* arr, int num, int left, int mid, int right, int size );
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int size{ 9 };
	int num{};
	int left{ 0 };
	int mid{};
	int right{ size  };
	int* arr_ptr = new int [9] { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	std::cout << "Введите точку отчета :";
	std::cin >> num;
	std::cout << std::endl;
	std::cout <<"Количество элементов больше " << num << " : " << sort(arr_ptr, num, left, mid, right, size);
	delete [] arr_ptr;
	return EXIT_SUCCESS;
}

int sort(int* arr, int num, int left, int mid, int right, int size) {
	while (left <= right) {
		mid = (left + right) / 2;
		if (num >= arr[mid]) { left = mid+1; }
		else if (num < arr[mid]) { right = mid-1; }
	}
	if (size - mid - 1 == -1) return 0;
	if (arr[mid] == num) return size - mid-1;
	 if (arr[mid] > num) return size - mid;
	 else if (arr[mid] < num) return size - mid-1;
	 return 1234;
}