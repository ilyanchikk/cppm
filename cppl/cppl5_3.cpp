#include <Windows.h>
#include <iostream>
#include <vector>

template<class T>
class SumCount {
public:
    SumCount(const std::vector<T>& vect) : data(vect) {}
    void operator()()  {
        for (auto var : data) {
            if (var % 3 == 0) {
                sum += var;
                count++;
            }
        }
    }
    void get_sum() {
        std::cout <<"[OUT] get_sum() = " << sum << std::endl;
    }
    void get_count() {
        std::cout << "[OUT] get_count() = " << count << std::endl;
    }
private:
    std::vector<T> data;
    T count{0};
    T sum{0};
};
template<class T>
void print_vect(const std::vector<T>& vect);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> vect = { 4,1,3,6,25,54};
    print_vect(vect);
    SumCount<int> sumcount(vect);
    sumcount();
    sumcount.get_count();
    sumcount.get_sum();

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

