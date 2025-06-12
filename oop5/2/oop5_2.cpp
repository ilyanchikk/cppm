#include <iostream>
#include <string>
#include <Windows.h>

class Shape {
protected:
	std::string type{};
	int sides;
public:
	Shape(int sides) : sides(sides) {
		type = "Фигура";
	}
	virtual void print_info() {
		std::cout << type << std::endl;
		std::cout << "Количество сторон: " << sides << std::endl;
		std::cout << std::endl;
	};
};

class Triangle : public Shape {
protected:
	int a, b, c, A, B, C{};
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C) { 
		type = "Треугольник";
	}
	void print_info() override {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
		std::cout << std::endl;
	}

};

class Quadangle : public Shape {
protected:
	int a, b, c, d, A, B, C, D{};
public:
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		type = "Четырехугольник";
	}

	void print_info() override {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
		std::cout << std::endl;
	}
};

class PRTriangle : public Triangle {
public:
	PRTriangle(int a, int b, int A, int B, int C)
		: Triangle(a, b, 90, A, B, C) {
		type = "Прямоугольный треугольник";
	}
};

class RBTriangle : public Triangle {
public:
	RBTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A) {
		type = "Равнобедренный треугольник";
	}
};

class RSTTriangle : public Triangle {
public:
	RSTTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60) {
		type = "Равносторонний треугольник";
	}
};

class Rctngl : public Quadangle {
public:
	Rctngl(int a, int b)
		: Quadangle(a, b, a, b, 90, 90, 90, 90) {
		type = "Прямоугольник";
	}
};

class Square : public Quadangle {
public:
	Square(int a)
		: Quadangle(a, a, a, a, 90, 90, 90, 90) {
		type = "Квадрат";
	}
};

class Parallelogram : public Quadangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadangle(a, b, a, b, A, B, A, B) {
		type = "Параллелограмм";
	}
};

class Romb : public Quadangle {
public:
	Romb(int a, int A, int B)
		: Quadangle(a, a, a, a, A, B, A, B) {
		type = "Ромб";
	}
};

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
