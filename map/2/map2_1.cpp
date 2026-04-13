#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <atomic>

std::atomic<int> count{ 0 };
int value{ 10 };

void client();
void oper();


int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::thread t1(client);
	std::thread t2(oper);
	t1.join();
	t2.join();
	return 0;
}

void client() {
	while (value != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count.fetch_add(1,std::memory_order_relaxed);
		value--;
		system("cls");
		std::cout << "Очередь клиентов: " << count << std::endl;
	}
}
void oper() {
	int clients = value;
	while (clients != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		count.fetch_sub(1, std::memory_order_relaxed);
		clients--;
		system("cls");
		std::cout << "Очередь клиентов: " << count << std::endl;
	}
}