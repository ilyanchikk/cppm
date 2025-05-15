
#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
	int sides_count{};
	std::string name{};
public:
	 Figure () { name = "Фигура"; }
	 int get_sides_count(){	return sides_count; }
	 std::string get_name() { return name;  }
};

class Triangle : public Figure {
public:
	Triangle() { sides_count = 3; name = "Треугольник"; }
};

class Quadrangle : public Figure {
public:
	Quadrangle() { sides_count = 4; name= "Четырехугольник"; }
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << "Количество сторон: " << std::endl;
	std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
	std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
	std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;
}
