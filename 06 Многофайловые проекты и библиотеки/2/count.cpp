#include "count.h"
#include <iostream>

Count::Count(int num) {
	this->num = num;
}
Count::Count() {
	this->num = 1;
}
void Count::plus() { ++num; }
void Count::minus() { --num; }
int Count::getnum() { return num; }