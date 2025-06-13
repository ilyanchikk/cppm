#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
protected:
	std::string type{};
	int sides{};
public:
	Shape(int sides);
	virtual void print_info();
};

#endif
