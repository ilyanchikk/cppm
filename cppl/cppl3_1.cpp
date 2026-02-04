#include <Windows.h>
#include <iostream>

class smartArray {
private:
    int* data{};
    int size{};
    int number{};
    int count{ 0 };
public: 
    smartArray(int asize) { 
        data = new int[asize];
        size = asize; 
    }
    int get_element(int index) { 
        if (index < 0 ||
            index >= size) {
            throw;
        }
        else return data[index]; 
    }
    void add_element(int anumber) { 
        if (count<0 || 
            count > size - 1) {
            std::cout << "Задан неверный или отсутствующий индекс." << std::endl;
            throw;
        }
        else {
            number = anumber;
            data[count] = number;
            count++;
        }
    }
        ~smartArray() { 
            delete[] data;
        }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        smartArray arr(5);
        arr.add_element(12);
        arr.add_element(22);
        arr.add_element(32);
        arr.add_element(42);
        arr.add_element(52);
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;
        std::cout << arr.get_element(3) << std::endl;
        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
       
    return EXIT_SUCCESS;
}
