#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <Windows.h>

void modif(int& x);
void print(std::vector<int>& vec);
template<typename Iter, typename Func>
void parallel_for_each(Iter first, Iter last, Func func);

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::vector<int> vec(10);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    for (auto& el : vec) {
        el = dis(gen);
    }

    std::cout << "Исходные элементы: ";
    print(vec);
    
    parallel_for_each(vec.begin(), vec.end(), modif);
    std::cout << "Модифицированные элементы (+1): ";
    print(vec);

    return 0;
}

void modif(int& x) {
    x++;
}
void print(std::vector<int>& vec) {
    for (int el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

template<typename Iter, typename Func>
void parallel_for_each(Iter first, Iter last, Func func) {
    size_t size = std::distance(first, last);

    if (size < 10) {
        std::for_each(first, last, func);
    }
    else {
    
        Iter middle = first;
        std::advance(middle, size / 2);

        auto future_left = async(parallel_for_each<Iter, Func>, first, middle, func);
        parallel_for_each(middle, last, func);

        future_left.get();
    }
}