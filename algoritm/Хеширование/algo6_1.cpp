#include <Windows.h>
#include <iostream>

int simple_string_hash(std::string input);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string input{};
    do {
        std::cout << "Введите строку: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Наивный хэш строки: " << input << ": " << simple_string_hash(input) << std::endl;
    } while (input != "exit");

    return EXIT_SUCCESS;
}
int simple_string_hash(std::string input) {
    int   out{};
    for (int i : input) {
        out = out +i;
    }
    return out;
}