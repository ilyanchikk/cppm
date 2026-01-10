#include <Windows.h>
#include <iostream>
void fill_dynamic_arr(int* data, int logic, int fact);
void print_dynamic_arr(int* data, int logic, int fact);
void delete_dynamic_arr(int* data);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int fact{}, logic{};
   
    std::cout << "Введите фактический размер массива: ";
    std::cin >> fact;
    std::cout << std::endl;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logic;
    std::cout << std::endl;
    int* data = new int [fact] {'_'};
    if (logic > fact) { std::cout << " Ошибка! Логический размер массива не может превышать фактический !"; return 1; }
    if (logic ==0 && fact == 0) { std::cout << " Заданы неверные параметры, фактический и логический размер массива = 0"; return 1; }
     fill_dynamic_arr(data, logic,fact);
     print_dynamic_arr(data, logic, fact);
     delete_dynamic_arr(data);

    return EXIT_SUCCESS;
}
void fill_dynamic_arr(int* data, int logic, int fact) {
    int input{ 0 };
    for (int i = 0; i < logic; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> input;
        std::cout << std::endl;
        data[i] = input;
    }
}
void print_dynamic_arr(int* data, int logic, int fact) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < fact; i++) { 
        if(i >= logic)  std::cout << "_ ";
        else std::cout << data[i] << " ";
    }
}
void delete_dynamic_arr(int* data) {
    delete[] data;
}