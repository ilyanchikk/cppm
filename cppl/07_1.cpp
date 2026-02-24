#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

int main() {

	std::string str = "Hello world!!";

	std::cout << "[IN] " << str << std::endl;
	std::map<char, int> dict;

	for (char c : str) {
		int count{ 0 };
		for (char k : str) {
			if (c == k) {
				count++;
			}
			dict[c] = count;
		}
		count = 0;
	}

	std::vector<std::pair<char, int>> vect(dict.begin(), dict.end());

	std::sort(vect.begin(), vect.end(), [](const auto& a, const auto& b) {
		return a.second > b.second; 
		});

	std::cout << "[OUT] " << std::endl;
	for (const auto& pair : vect) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	return 0;
}