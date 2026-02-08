#include <Windows.h>
#include <iostream>

class smartArray {
private:
    int* data{};
    int size{};
    int number{};
    int count{ 0 };
    int filledAr{};
public:
    smartArray(int asize) {
        data = new int[asize] {};
        size = asize;
    }
    smartArray(const smartArray& arr) {  //Коструктор копирования
        size = arr.size;
        data = new int[size] {};
        filledAr = arr.filledAr;
        for (int i = 0; i < filledAr; i++) {
            data[i] = arr.data[i];
        }
        std::cout << "Вызван конструктор копирования" << std::endl;
    }
    smartArray& operator=(const smartArray& arr) {  //Оператор присваивания
        if (this != &arr) {
            delete[] data;
            size = arr.size;
            data = new int[size] {};
            filledAr = arr.filledAr;
            for (int i = 0; i < filledAr; i++) {
                data[i] = arr.data[i];
            }
            std::cout << "Вызван оператор присваивания" << std::endl;
            return *this;
        }
        return *this;
    }
    int get_element(int index) {
        if (index < 0 ||
            index >= size) {
            throw;
        }
        else return data[index];
    }
    int* get_data() {
        return data;
    }
    int get_size() {
        return size;
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
            filledAr = count;
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
        smartArray arr(3); //создание класса
        arr.add_element(1);
        arr.add_element(2);
        arr.add_element(3);

        std::cout << arr.get_data() << std::endl;
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;

        smartArray arr2(arr); // копирование с помощью конструктора копирования
        std::cout << arr2.get_data() << std::endl;
        std::cout << arr2.get_element(0) << std::endl;
        std::cout << arr2.get_element(1) << std::endl;
        std::cout << arr2.get_element(2) << std::endl;

        arr = arr2; // оператор присваивания
        std::cout << arr.get_data() << std::endl;
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;

        arr = arr; // присваивание самому себе
        std::cout << arr.get_data() << std::endl;
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;


    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return EXIT_SUCCESS;
}