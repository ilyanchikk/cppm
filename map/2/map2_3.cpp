#include <iostream>
#include <mutex>
#include <Windows.h>

class Data {
private:
    int value;
    std::mutex mtx;

public:
     Data(int val) : value(val) {}

    int getValue() const {
        return value;
    }

    friend void swap_lock(Data& a, Data& b);
    friend void swap_scoped_lock(Data& a, Data& b);
    friend void swap_unique_lock(Data& a, Data& b);
};


void swap_lock(Data& a, Data& b) {
    
    std::lock(a.mtx, b.mtx);

    std::lock_guard<std::mutex> lock_a(a.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lock_b(b.mtx, std::adopt_lock);

    std::swap(a.value, b.value);
}


void swap_scoped_lock(Data& a, Data& b) {
    std::scoped_lock lock(a.mtx, b.mtx);

    std::swap(a.value, b.value);
}

void swap_unique_lock(Data& a, Data& b) {
    std::unique_lock<std::mutex> lock_a(a.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(b.mtx, std::defer_lock);

    std::lock(lock_a, lock_b);
    std::swap(a.value, b.value);
}


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Data a1(123);
    Data a2(321);

    std::cout << "Начальные значения : \n";
    std::cout << "a1 = " << a1.getValue() << ", a2 = " << a2.getValue() << "\n";

  
    swap_lock(a1, a2);
    std::cout << "Функция swap_lock:\n";
    std::cout << "a1 = " << a1.getValue() << ", a2 = " << a2.getValue() << "\n";

    swap_scoped_lock(a1, a2);
    std::cout << "Функция swap_scoped_lock:\n";
    std::cout << "a1 = " << a1.getValue() << ", a2 = " << a2.getValue() << "\n";

    swap_unique_lock(a1, a2);
    std::cout << "Функция swap_unique_lock:\n";
    std::cout << "a1 = " << a1.getValue() << ", a2 = " << a2.getValue() << "\n";

    return 0;
}