
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

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
	std::string get_output_address() {
		std::string s;
		return s += city + ' ' + street + ' ' + std::to_string(house) + ' ' + std::to_string(flat) + '\n';
	}
	std::string get_city() { return city; }
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream in_file("in.txt");
	int size{};
	std::string city{};
	std::string street{};
	int house{};
	int flat{};
	if (in_file.is_open()) {
		in_file >> size;
		Addres** add_ptr = new Addres* [size];
		for (int i = 0; i < size; ++i) {
			in_file >> city;
			in_file >> street;
			in_file >> house;
			in_file >> flat;
			add_ptr[i] = new Addres(city, street, house, flat);
		}
		Addres* temp = new Addres("null", "null", 0, 0);
		for (int j = 0; j < size; ++j) {
			for (int i = j; i < size - 1; ++i) {
				if (add_ptr[i]->get_city() > add_ptr[i + 1]->get_city())
				{
					temp = add_ptr[i];
					add_ptr[i] = add_ptr[i + 1];
					add_ptr[i + 1] = temp;
				}
			}
		}
		in_file.close();
		std::ofstream out_file("out.txt");
		out_file << size;
		out_file << '\n';
		for (int i = 0; i < size; ++i) {
			out_file << add_ptr[i]->get_output_address();
		}
		out_file.close();
		delete[] add_ptr;
		std::cout << "Информация выведена в out.txt";
	}
	else std::cout << "Ошибка открытия входного файла!.";

}