#ifndef QUADRIANGLE_H
#define QUADRIANGLE_H
#include "Shape.h"

class Quadangle : public Shape {
protected:
	std::string type{ "Четырехугольник" };
	int a, b, c, d, A, B, C, D{};
public:
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D);
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string type);

	void print_info() override;
};

#endif
