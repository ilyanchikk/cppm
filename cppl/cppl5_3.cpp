#include <Windows.h>
#include <iostream>
#include <vector>

template<class T>
class Sum {
public:
    Sum(const std::vector<T>& vect) : data(vect) {}
    T operator()() const {
        T tmp{0};
        for (auto var : data) {
            if (var % 3 == 0) {
                tmp += var;
            }
        }
        return tmp;
   }
private:
    std::vector<T> data;
};
template<class T>
class Count {
public:
    Count(const std::vector<T>& vect) : data(vect) {}
    T operator()() const {
        T count{ 0 };
        for (auto var : data) {
            if (var % 3 == 0) {
                count++;
            }
        }
        return count;
    }
private:
    std::vector<T> data;
};
template<class T>
void print_vect(const std::vector<T>& vect);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> vect = { 4,1,3,6,25,54};
    print_vect(vect);
    
    Sum<int> get_sum(vect);
    std::cout << "[OUT] " << "get_sum() = " << get_sum() << std::endl;


    Count<int> get_count(vect);
    std::cout << "[OUT] " << "get_count() = " << get_count() << std::endl;
    return EXIT_SUCCESS;
}

template<class T>
void print_vect(const std::vector<T>& vect) {
    std::cout << "[IN] ";
    for (auto var : vect) {
        std::cout << var << " ";
    }
    std::cout << std::endl;
}