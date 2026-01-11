#include <Windows.h>
#include <iostream>

int real_string_hash(std::string input, int p, int n);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string input{};
    int p{}, n{};
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << std::endl;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << std::endl;
    do {
        std::cout << "Введите строку: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Хэш строки: " << input << ": " << real_string_hash(input, p,n) << std::endl;
    } while (input != "exit");

    return EXIT_SUCCESS;
}
int real_string_hash(std::string input,int p, int n) {
    long long out{};
    int mult{0};
    for (int i : input) {
        out = out + (i * pow(p, mult));
        mult++;
    }
    out = out % n;
    return out;
}