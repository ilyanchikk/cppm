#include <Windows.h>
#include <vector>
#include <iostream>

void quick_sort(int* data, int begin, int end);
void printArray(int* data, int size);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 18;
    int begin{ 0 }, end{size--};

    int* data = new int [size] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62,};
 

    std::cout << "Исходный массив ";
    printArray(data, size);
    quick_sort(data,begin, size);

    std::cout << "Откорректированный массив: ";
    printArray(data, size);
    return EXIT_SUCCESS;
}

void quick_sort(int* data, int begin, int end) {
        int l = begin, r = end;
        int v = data[l + (r - l) / 2];
        while (l <= r)
        {
            while (data[l] < v) l++;
            while (data[r] > v) r--;
            if (l <= r)
            {
                int tmp = data[l];
                data[l] = data[r];
                data[r] = tmp;
                l++, r--;
            }
        }
        if (begin < r)
            quick_sort(data, begin, r);
        if (l < end)
            quick_sort(data, l, end);
    }
   

void printArray(int* data,int size) {
    for (int i = 0; i <= size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}