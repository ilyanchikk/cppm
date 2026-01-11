#include <Windows.h>
#include <iostream>

int simple_string_hash(std::string input, int size);
void alg_rab(std::string inputStr, std::string inputSearch, int size, int size2, int* arr_ptr);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string inputStr{}, inputSearch{};
    std::cout << "Введите строку в которой будет осуществляться поиск: ";
    std::cin >> inputStr;
    std::cout << std::endl;
    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> inputSearch;
        std::cout << std::endl;
        int size = inputStr.size();
        int size2 = inputSearch.size();
        int* arr_ptr = new int [size] {};
        for (int i = 0; i < size; i++) {
            arr_ptr[i] = inputStr[i]; // hash = number
        }
        alg_rab(inputStr, inputSearch, size, size2, arr_ptr);


    } while (inputSearch != "exit");
    return EXIT_SUCCESS;
}
int simple_string_hash(std::string input, int size) { //Вычисление простого хеша
    int   out{};
    for (int i = 0; i < size; i++) {
        out = out + input[i];
    }
    return out;
}
void alg_rab(std::string inputStr, std::string inputSearch, int size, int size2, int*arr_ptr) {
    int hash2{};
    int hash1{ simple_string_hash(inputSearch, size2) };
    int count2{ 0 };
    for (int i = 0; i < size - size2; i++) { 
        if (i == 0) hash2 = simple_string_hash(inputStr, size2);
        else hash2 = hash2 - arr_ptr[i - 1] + arr_ptr[size2 + i - 1];
        if (hash1 == hash2) {
            int count{ 0 };
            for (int k = 0; k < size2; k++) {
                if (inputSearch[k] == inputStr[k + i]) count++;
            }
            if (count == size2) {
                std::cout << "Подстрока " << inputSearch << " найдена по индексу: " << i << std::endl;
                count2 = count;
                break;
            }
        }
        
    }
    if (count2 != size2) {
        std::cout << "Подстрока " << inputSearch << "  не найдена" << std::endl;

    }
}
