#ifndef RCTNGL_H
#define RCTNGL_H

class Rctngl : public Quadangle {
public:
	Rctngl(int a, int b)
		: Quadangle(a, b, a, b, 90, 90, 90, 90) {
		type = "Прямоугольник";
	}
};

#endif