#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cstdlib>


#include <assert.h> 

class IndexOutOfBoundsException {};
class IntArray {
private:
	int* m_ptr{ nullptr };//Implementation details
	int m_size{ 0 };//Implementation details
public:
	IntArray(const IntArray& source) {//Making a deep copy with a copy constructor 
		if (!source.IsEmpty()) {
			m_size = source.m_size;
			m_ptr = new int[m_size];//Declaring new memeory on the heap

			for (int i{ 0 }; i < m_size; i++) {
				m_ptr[i] = source.m_ptr[i];
			}
		}
	}
	
	friend void swap(IntArray& a, IntArray& b) {//Swap function for arrays.
		std::swap(a.m_ptr, b.m_ptr);
		std::swap(a.m_size, b.m_size);
	}
	

	IntArray& operator=(IntArray source) {
			swap(*this, source);
			return *this;

		}
		IntArray(IntArray&& source) { //Transeferring arrays.
			//Transfer ownership (stealing data) from source
			m_ptr = source.m_ptr;
			m_size = source.m_size;
			//Clearing the source
			source.m_ptr = nullptr;
			source.m_size = 0;

		}

		IntArray()= default;//Syenthesize a default constructor
	//We used explicit to prevent implicit conversion from int to intarray Note: USe explicit with one arg constructors
	explicit IntArray(int size) {//Function that create an array of the given size 
		if (size != 0) {
			m_ptr = new int[size] {};//using {}empty init to properly intialize the array size to 0 without this you will wind up with Garbage intial values
			m_size = size;
			delete[] m_ptr;
		}
	}
	int size() const { //this func is const becasue it doesn't chnage the array size
		return m_size;
	}
	bool IsEmpty() const { //this func is const becasue it doesn't chnage the array size
		return (m_size == 0);
	}
	int& operator[](int index) { //function to access the array indexes with an overloaded operator //Added the & to return by refernce not by value
		if (!IsValidIndex(index)) {
			throw IndexOutOfBoundsException{};//bounds checking
		}
		else {
			return m_ptr[index];
		}
	}
	bool IsValidIndex(int index)const {//Bound checking function
		return (index >= 0) && (index < m_size);
	}
	////              OVerloading operator<< for Arrays
	//friend std::ostream& operator<<(std::ostream& os, const IntArray& a) {
	//	os << "[";
		//for (int i{ 0 }; i < a.size(); i++) {
		//	os << a[i] << " ";
		//}
		//os << "]";
	//	return os;
	//}
};

int main() {

	//std::cout << "Creating an Empty array\n";
	//IntArray O{};
	//std::cout << O.size() << std::endl;
	//assert(O.IsEmpty());
	//std::cout << "Creating an Array that has 10 elements\n";
	//IntArray b{ 10 };
	//std::cout << "b.size() is " << b.size() << "\n";
	//assert(!b.IsEmpty());//checking a condition at the run-time check checking if b.size is not empty if this is false it will terminate the program
	//Allowing external access to the array content
	//we use overloaded operator
	//IntArray a{ 3 };
	//std::cout << "Setting a[0] = 10 " << std::endl;
	//for (int i{ 0 }; i < 3; i++) {
	//	a[i] = i;
		//std::cout << a[i] ;
	//}
	//std::cout << std::endl;
	//std::cout << a.IsValidIndex(100);
	try {
		IntArray a{ 10 };
		for (int i{ 0 }; i < a.size(); i++) {
			a[i] = (i + 1) * 10;
			std::cout << a[i] << " ";
		}
		std::cout << a[5];
		std::cout << "Array size is " << a.size() << std::endl;
		std::cout << "Enter array index" << std::endl;
		int index{ 05 };
		std::cin >> index;
		std::cout << "The Elementat index " << index << " is " << a[index] << std::endl;


	}
	catch (const IndexOutOfBoundsException & e) {//Boung checking if the array index is out of range
	//	std::cout << "Error: Invalid array index\n";
	//}
	// Upcoming subjects
//Improving Array Implementation
//Copying Arrays Shallow vs deep copy
//Copy and swap idiom
//Move semantics
//Generic Array<T> using templates




	}
}

//Note: Memory Allocated with new must be released invoking delete but do not forget to provide proper destructor implementation
// Upcoming subjects
//Improving Array Implementation
//Copying Arrays Shallow vs deep copy If you want a deep copy array you will need to write your own version of customer copy constructor
//Copy and swap idiom
//Move semantics
//Generic Array<T> using templates

