#include <Windows.h>
#include <iostream>

class smartArray {
private:
    int* data{};
    int size{};
    int number{};
    int count{ 0 };
public:
    smartArray(int asize) { data = new int[asize]; size = asize; }
    int get_element(int index) { if (index<0 || index > size) return 0; else return data[index]; }
    int* get_data() { return data; }
    int get_size() { return size; }
    void add_element(int anumber) {
        if (count<0 || count > size - 1) {
            std::cout << "Задан неверный или отсутствующий индекс." << std::endl;
            throw;
        }
        else {
            number = anumber;
            data[count] = number;
            count++;
        }
    }
    ~smartArray() { delete[] data; }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        smartArray arr(3);
        arr.add_element(1);
        arr.add_element(2);
        arr.add_element(3);
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;

        smartArray arr2(3);
        arr2.add_element(11);
        arr2.add_element(12);
        arr2.add_element(13);
        std::cout << arr2.get_element(0) << std::endl;
        std::cout << arr2.get_element(1) << std::endl;
        std::cout << arr2.get_element(2) << std::endl;

        for (int i = 0; i < arr.get_size(); i++) {
            arr.get_data()[i] = arr2.get_data()[i];
        }
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
