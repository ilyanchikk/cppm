#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram : public Quadangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadangle(a, b, a, b, A, B, A, B, "Параллелограмм") {
	}
};

#endif
