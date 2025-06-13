#include <string>
#include <iostream>
#include "Triangle.h"

	Triangle::Triangle(int a, int b, int c, int A, int B, int C)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C) {
		type = "Треугольник";
	}
	void Triangle::print_info() {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
		std::cout << std::endl;
	}