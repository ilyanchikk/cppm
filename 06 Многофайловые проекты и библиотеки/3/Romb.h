#ifndef ROMB_H
#define ROMB_H

class Romb : public Quadangle {
public:
	Romb(int a, int A, int B)
		: Quadangle(a, a, a, a, A, B, A, B) {
		type = "Ромб";
	}
};

#endif
