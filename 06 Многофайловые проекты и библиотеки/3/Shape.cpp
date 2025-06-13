#include "Shape.h"
#include <iostream>

Shape::Shape(int sides) : sides(sides) {
	type = "Фигура";
}
void Shape::print_info() {
	std::cout << type << std::endl;
	std::cout << "Количество сторон: " << sides << std::endl;
	std::cout << std::endl;
}