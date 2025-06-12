#ifndef COUNT_H
#define COUNT_H

class Count {
private:
	int num{};
public:
	Count(int num);
	Count();
	void plus();
	void minus();
	int getnum();
};

#endif