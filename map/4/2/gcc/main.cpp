#include <iostream>
#include <chrono>
#include <thread>

int count{ 0 };
int value{ 10 };

void client();
void oper();

int main() {
	std::thread t1(client);
	std::thread t2(oper);
	t1.join();
	t2.join();
	return 0;
}

void client() {
	while (value != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count++;
		value--;
		std::cout << "Очередь клиентов: " << count << std::endl;
	}
}
void oper() {
	int clients = value;
	while (clients != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		count--;
		clients--;
		std::cout << "Очередь клиентов: " << count << std::endl;
	}
}