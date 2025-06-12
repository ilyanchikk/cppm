#include <iostream>
#include <string>
#include <Windows.h>
#include "Shape.h"
#include "Triangle.h"
#include "Quadriangle.h"
#include "PRTriangle.h"
#include "RBTriangle.h"
#include "RSTTriangle.h"
#include "Rctngl.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Romb.h"

void print_info(Shape* shape) {
	shape->print_info();
} 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Shape shape(0);
	print_info(&shape);
	Triangle trg(10, 20, 30, 40, 50, 60);
	print_info(&trg);
	PRTriangle prtrg(10, 20, 30, 50, 60);
	print_info(&prtrg);
	RBTriangle rbtrg(10, 20, 50, 60);
	print_info(&rbtrg);
	RSTTriangle rsttrg(30);
	print_info(&rsttrg);
	Quadangle qad(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&qad);
	Rctngl rect(10, 20);
	print_info(&rect);
	Square sqare(20);
	print_info(&sqare);
	Parallelogram prlg(20, 30, 30, 40);
	print_info(&prlg);
	Romb romb(30, 30, 40);
	print_info(&romb);

	return 0;
}
