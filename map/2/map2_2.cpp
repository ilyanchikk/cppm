#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <atomic>
#include <random>
#include <mutex>     
#include <iomanip>

int calc();
void print_th(int length_calc, int num_th);
void create_th(int threads, int length_calc);
void moveCursor(int row, int col);

std::mutex c_mutex;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int threads{5};
	int length_calc{20};
	for (int i = 0; i < threads; i++) {
		std::cout << "\n";
	}
	
	create_th(threads, length_calc);
	
	moveCursor(threads+4, 1);
	return 0;
}

int calc() {
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> distr(10, 400);
	return distr(gen);
}
void create_th(int threads, int length_calc) {
	std::vector<std::thread> t;
	for (int i = 0; i < threads; i++) {
		t.push_back(std::thread(print_th, length_calc, i+1));
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
		
	
	}
	for (int i = 0; i < threads; i++) {
		t[i].join();
	}
}
void moveCursor(int row, int col) {
	std::cout << "\033[" << row << ";" << col << "H";
}
void print_th(int length_calc, int num_th) {
	
	int row{ num_th  };
	int colunm{ 1 };
	
	moveCursor(row, colunm);
	
	std::cout << "Номер потока :" << num_th << ", id потока:  "  << std::this_thread::get_id();
	
	auto StartTime = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < length_calc; i++) {
		std::unique_lock<std::mutex> lk(c_mutex);
		int row{ num_th };
		int colunm{i+38};
		
		moveCursor(row, colunm);
		lk.unlock();
		std::cout << "█";
		std::this_thread::sleep_for(std::chrono::milliseconds(calc()));
		lk.lock();
		
	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	
		moveCursor(row, length_calc+40);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - StartTime);
		std::cout << "Время выполнения: " << duration.count() << "мcек";
}
