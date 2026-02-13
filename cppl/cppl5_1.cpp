#include <Windows.h>
#include <iostream>
#include <vector>

template<typename T>
void square(T num);

template<typename T>
void square( std::vector<T> vect, int size);



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int in = 4;
    std::vector<int> vect{ -1,4,8 };
    int size = vect.size();
    square(in);
    square(vect,size);

    return EXIT_SUCCESS;
}
template<typename T>
void square(T num) {
    std::cout << "[IN] " << num << std::endl;
    std::cout << "[OUT] " << num*num << std::endl;
}

template<typename T>
void square( std::vector<T> vect, int size) {
    std::cout << "[IN] ";
    for (int i = 0; i < size; i++) {
        std::cout << vect[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "[OUT] ";
    for (int i = 0; i < size; i++) {
        vect[i] *= vect[i];
        std::cout << vect[i] << ", ";
    }
    std::cout << std::endl;
}
