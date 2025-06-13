#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle : public Shape {
protected:
	int a, b, c, A, B, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C);
		
	void print_info() override;
};

#endif