#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

constexpr int kNotFound = -1;
void print(const std::vector<int>& v);

int search(int element, const int* v, int size);
//Implementing linear serach Algorithm
int main() {
	std::vector <int> v{ 44,66,88,33,45,50,70,640,60 };
	std::cout << "Element to search?";
	print(v);
	int x;
	std::cin >> x;
	int pos = search(x, v.data(), v.size());
	if (pos == kNotFound) {
		std::cout << "Element not found";
	}
	else {
		std::cout << pos;
	}
}

int search(int element, const int* v, int size) {
	//For each itema in the input array
	//compare it with the search element
	for (int i = 0; i < size; i++) {
		if (v[i] == element) {
			//element found
			//return its position to the caller
			return i;
		}
	}
	//Element not found
	return kNotFound;
}
void print(const std::vector<int>& v) {
	for (int x : v) {
		std::cout << "[" << x << "] ";
	}
}