#include <iostream>
#include <Windows.h>
#include <string>

struct addres {
	std::string city;
	std::string street;
	int house;
	int flat;
	int index;
};
void print_addres(addres* p_add);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	addres Gog = {"������","���������",12,2,12345};
	addres Sasha = { "�������","������",22,22,12345 };
	addres* p_add = &Gog;
	print_addres(p_add);
	addres* p_add2 = &Sasha;
	print_addres(p_add2);
	return 0;
}

void print_addres(addres* p_add) {
	std::cout << "�����: " << p_add->city << std::endl;
	std::cout << "�����: " << p_add->street << std::endl;
	std::cout << "����� ����: " << p_add->house << std::endl;
	std::cout << "����� ��������: " << p_add->flat << std::endl;
	std::cout << "������: " << p_add->index << std::endl;
	std::cout << std::endl;
}