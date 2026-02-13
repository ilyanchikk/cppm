#include <Windows.h>
#include <iostream>

template<class T>
class Table {
public:
    Table(int arows, int acolumns) {
        rows = arows;
        columns = acolumns;
        size = rows * columns;
        data = new T* [rows] {};
        for (int i = 0; i < rows; i++) {
           data[i] = new T[columns]{};
        }
    }
    T* operator[](const T rows) {
        return data[rows];
    }
    const T* operator[](const T rows) const {
        return data[rows];
    }
    const int get_size() {
        return size;
    }
    ~Table() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
private:
    T** data{};
    int size{};
    int rows{};
    int columns{};


};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Table<int> table(2,3);
    table[0][0] = 4;
    std::cout << table[0][0] << std::endl;
    std::cout << table.get_size() << std::endl;

    return EXIT_SUCCESS;
}

