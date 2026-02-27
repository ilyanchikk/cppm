#include <iostream>
#include <vector>
#include <algorithm>
void del_dubl(std::vector<int>& vect);
void print_vect(std::vector<int>& vect);

int main() {
	std::vector<int> vect{ 1,1,2,5,6,1,2,4 };
	print_vect(vect);
	del_dubl(vect);
	print_vect(vect);
	return 0;
}
void del_dubl(std::vector<int>& vect) {
	std::sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
}
void print_vect(std::vector<int>& vect) {
	for (int i : vect) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}