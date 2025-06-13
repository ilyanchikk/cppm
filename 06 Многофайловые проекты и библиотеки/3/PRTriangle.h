#ifndef PRTRIANGLE_H
#define PRTRIANGLE_H

class PRTriangle : public Triangle {
public:
	PRTriangle(int a, int b, int A, int B, int C)
		: Triangle(a, b, 90, A, B, C) {
		type = "Прямоугольный треугольник";
	}
};

#endif