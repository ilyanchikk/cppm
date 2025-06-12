#ifndef RSTTRIANGLE_H
#define RSTTRIANGLE_H

class RSTTriangle : public Triangle {
public:
	RSTTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
	}
};

#endif