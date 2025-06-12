#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle : public Shape {
protected:
	std::string type{ "Треугольник" };
	int a, b, c, A, B, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C);
		
	Triangle(int a, int b, int c, int A, int B, int C, std::string type);
		
	void print_info() override;
};

#endif