#ifndef RBTRIANGLE_H
#define RBTRIANGLE_H

class RBTriangle : public Triangle {
public:
	RBTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A) {
		type = "Равнобедренный треугольник";
	}
};

#endif