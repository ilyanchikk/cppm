#include <Windows.h>
#include <iostream>
void fill_dynamic_arr(int* data, int logic, int fact);
void print_dynamic_arr(int* data, int logic, int fact);
void delete_dynamic_arr(int* data);
void add_dynamic_arr(int* data, int logic, int fact);
int* extension_dynamic_arr(int* data, int fact, int logic);

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
    int* data = new int [fact] {};
    if (logic > fact) { std::cout << " Ошибка! Логический размер массива не может превышать фактический !"; return 1; }
    if (logic == 0 && fact == 0) { std::cout << " Заданы неверные параметры, фактический и логический размер массива = 0"; return 1; }
    fill_dynamic_arr(data, logic, fact); 
    print_dynamic_arr(data, logic, fact);
    add_dynamic_arr(data, logic, fact);
    delete_dynamic_arr(data);

    return EXIT_SUCCESS;
}
void fill_dynamic_arr(int* data, int logic, int fact) { //Первичное заполнение массива
    int input{ 0 };
    for (int i = 0; i < logic; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> input;
        std::cout << std::endl;
        data[i] = input;
    }
}
void print_dynamic_arr(int* data, int logic, int fact) { //Вывод массива на экран
    std::cout << "Динамический массив: ";
    for (int i = 0; i < fact; i++) {
        if (i >= logic)  std::cout << "_ ";
        else std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
void add_dynamic_arr(int* data, int logic, int fact) { //Добавление новых чисел в динамический массив
    int add{};
    for (int i = logic; i < fact; i++) {
        std::cout << "Введите элемент для добавления или 555 для выхода: ";
        std::cin >> add;
        std::cout << std::endl;
        if (add == 555) { std::cout << "Работа программы завершена. ";  return; }
       else if (i <= logic) {
            data[i] = add;
            logic++;
            print_dynamic_arr(data, logic, fact);
        }
      }
        fact *= 2;
        data = extension_dynamic_arr(data, fact, logic); //Возвращаем указатель на новый массив
        add_dynamic_arr(data, logic, fact); //Рекурсивно вызваем себя что бы продолжить работу программы
    }
        
void delete_dynamic_arr(int* data) {//Удаление массива
    delete[] data;
}
int* extension_dynamic_arr(int* data, int fact, int logic) {//Увеличение массива в 2 раза
    int* data_copy = new int [fact] {};
    for (int i = 0; i < logic; i++) {
        data_copy[i] = data[i];
    }
    return data_copy;
}