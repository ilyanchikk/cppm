﻿
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
	Addres() {
		city = "";
		street = "";
		house = 0;
		flat = 0;
	}
	Addres(std::string city, std::string street, int house, int flat) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->flat = flat;
	}
	std::string get_output_address() {
		return city + " " + street + " " + std::to_string(house) + " " + std::to_string(flat) + '\n';
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
		Addres* add_ptr = new Addres[size];
		for (int i = 0; i < size; i++)
		{
			in_file >> city >> street >> house >> flat;
			add_ptr[i] = Addres(city, street, house, flat);
		}
		Addres temp;
		for (int j = 0; j < size; ++j) {
			for (int i = 0; i < size - 1; ++i) {
				if (add_ptr[i].get_city() > add_ptr[i + 1].get_city())
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
			out_file << add_ptr[i].get_output_address();
		}
		out_file.close();
		delete[] add_ptr;
		std::cout << "information out in out.txt";
	}
	else std::cout << "error open file in.txt";
	return 0;
}