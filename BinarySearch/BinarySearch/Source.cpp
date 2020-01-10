#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <list>


//Binary search

int BinarySearch(int element, const int* v, int size) {
	int left = 0;
	int right = size - 1;//-1 becasue array indexes are zero-based also apply to vectors
	while (left <= right) {//if left > right then the element is not contained in the array
		int middle = (left + right) / 2;
		if (v[middle] == element) {
			//Element found
			return middle;
		}
		else if (v[middle] < element) {
			//search in the right half: (middle +1..right)
			left = middle + 1;
		}
		else if (v[middle] > element) {
			//search in the left-half: (left.. middle-1)
			right = middle - 1;
		}
	}
}
void reve(const std::vector <int>* v) {
	for (auto l : *v) {
		std::cout << l << " ";
	}
}
int main() {
	std::vector <int> v = { 1,2,3,4,5,6,7,8,98,34,56,78,88 };
	//reve(&v);
//	std::cout << std::endl;
	//int pos = BinarySearch(3, v.data(), v.size());
	//std::cout << pos << std::endl;
	std::list <int> l{ 1,2,3 };
	std::cout << l.front();

}

//Note: For sorted arrays prefer binary search to linear search





