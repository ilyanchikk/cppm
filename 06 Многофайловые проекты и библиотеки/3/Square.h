#ifndef SQUARE_H
#define SQUARE_H

class Square : public Quadangle {
public:
	Square(int a)
		: Quadangle(a, a, a, a, 90, 90, 90, 90, "Квадрат") {
	}
};

#endif