#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <future>

void min_el(std::vector<int>& vec, int begin, std::promise<int> prom);
void print_vect(std::vector<int>& vect);

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::vector<int> vec{ 10, 9,8,7,6,5,4,3,2,1 };
	std::cout << "Исходный вектор: " << std::endl;
	print_vect(vec);


	for (int i = 0; i < vec.size(); i++) {
		std::promise<int> prom;
		std::future<int> fut = prom.get_future();
		int begin = i;
		std::async(min_el, ref(vec), i, std::move(prom));
		fut.wait();
		int min_in = fut.get();
		std::swap(vec[i], vec[min_in]);
	}
	std::cout << "Отсортированный вектор вектор: " << std::endl;
	print_vect(vec);
	
	return 0;
}
void print_vect(std::vector<int>& vect) {
	for (int el : vect) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

void min_el(std::vector<int>& vec, int begin, std::promise<int> prom) {
	int size = vec.size();
	int min_ind = 0;
	for (int i = begin; i < size; i++) {
		if (vec[i] <= vec[begin]) {
			min_ind = i;
		}
	}
	prom.set_value(min_ind);
	}