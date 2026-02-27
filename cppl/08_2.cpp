#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>

template <typename T>
void print_container(T& container);

int main() {
	std::vector<int> vect1{ 1,1,5,5 };
	std::set<int> set1{ 1,2,3,4 };
	std::list<int> list1{ 3,3,4,4 };
	std::vector<double> vect2{ 1.5,2.3,3.3,4.3 };
	std::vector<std::string> vect3{ "hello","olleh" };
	std::vector<char> vect4{ 'a','b','c' };
	print_container(vect1);
	print_container(set1);
	print_container(list1);
	print_container(vect2);
	print_container(vect3);
	print_container(vect4);

	return 0;
}

template <typename T>
void print_container(T& container) {
	std::for_each(container.begin(), container.end(), [](const auto elem) {std::cout << elem << " "; }); 
	std::cout << std::endl;
}