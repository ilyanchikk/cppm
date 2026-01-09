#include <Windows.h>
#include <iostream>

void count_sort(int* data, int* tmp, const int begin, const int end);
void printArray(int* data, int size);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size{30};
    const int begin{ 10 };
    const int end{ 24 };

    int* data = new int [size] {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int* tmp = new int [size] {};

    std::cout << "Исходный массив: ";
    printArray(data, size);

    count_sort(data,tmp, begin,end);

    std::cout << "Временный массив: ";
    printArray(tmp, size);

    std::cout << "Отсортированный массив: ";
    printArray(data, size);
    delete[] data;
    delete[] tmp;
    return EXIT_SUCCESS;
}

void count_sort(int* data, int* tmp ,const int begin, const int end) {

    for (int i = 0; i < 30; i++) {
        tmp[data[i]] += 1;
    }
    int c{ 0 };
    for (int number = begin; number <= end; number++) {
        for (int i = 0; i < tmp[number]; i++) {
            data[c] = number;
            c++; 
        }
    }
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}