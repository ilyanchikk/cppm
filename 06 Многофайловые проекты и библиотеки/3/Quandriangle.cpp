#include "Quadriangle.h"
#include <string>
#include <iostream>


Quadangle::Quadangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
	}
Quadangle::Quadangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string type)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), type(type) {
	}

	void Quadangle::print_info() {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
		std::cout << std::endl;
	}