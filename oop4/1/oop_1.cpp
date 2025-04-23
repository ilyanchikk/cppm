
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

void input_addres(std::string* arr);

class Addres {
private:
	std::string city{};
	std::string street{};
	int house{};
	int flat{};
public:
	Addres(std::string city, std::string street, int house, int flat) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->flat = flat;
	}
	std::string get_output_address(std::ifstream file) {
		file >> city;
		file >> street;
		file >> house;
		file >> flat;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file ("in.txt");
	int size{};
	std::string city{};
	std::string street{};
	int house{};
	int flat{};
	if (file.is_open()) {
		file >> size;
		std::string* arr = new std::string[size]{};
		for (int i = 0; i < size; ++i) {
			file >> city;
			file >> street;
			file >> house;
			file >> flat;
			arr[i] = Addres(city, street, house, flat);
			
		}

		delete[] arr;
	}
	else std::cout << "Ошибка открытия файла!.";

}
void input_addres(std::string* arr) {

}