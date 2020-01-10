#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cstdlib>


//What is a pointer.

/*
A variable
1-That has a value in an address

What can be at that address
1-Another variable
A function

pointers point to a variable or functions?
if x is an int variable and its value is 10 then i can declare a pointer that points to it

to use the data that the pointer is pointing to you must know its type


*/


//Declaring pointer
//If we wanna declare a pointer we use the (*)for it.
//Must intialize a pointer var otherwise it will have garbage data 
//----------------------------------------------------------------
//Intializing a pointer.
/*
1-Intilaizing a pointer variables tp point nowhere.
2-Always intialize pointers
3-unintialized pointers contain Garbage data and can point "Any where".
that implies that the pointer is pointing anywhere.
4-If you don't intialize a pointer to point to a variable of function then you should
intialize it to nullptr to "make it null"

//Below is an example.
int main() {
	int* int_ptr{nullptr};
	std::cout << int_ptr << std::endl; //print out the value == which is zero becasue the pointer was intialized to null
	std::cout << &int_ptr;//this prints out the address of the pointer
}
*/

//Accessing pointers address and storing address in a pointer.
/*
The Address operator.
1-Variables are stored in uniqe addresses
2-Unary Operator
3-Evaluates to the address of its operand
Opernad cannot be a constant or expressin that evaluates temp values.

//Example 1.
int main() {
	int num{ 10 };

	std::cout << "Value of num is: " << num << std::endl;//this prints out the value that is stored in the address of int num which is 10.
	std::cout << "Size of num is: " << sizeof num << std::endl; //This preints out the size of num which is 4 bytes (This can differ from a machine to another)
	std::cout << "Address of num is: " << &num << std::endl; //This prints out the address of num (where num is allocated in the memeor) which is == 001AF8E4 this is not constant it can be chnaged (The address).
}
*/

//Example 2.
/*
Note***:
Don't confuse the size of a pointerand the size of what it points to
All pointers in a program have the same size
They may be pointing to a very large or small types
so the address of a vector or addrtess of a string etc...
All of them has the size of 4 bytes on my machine


int main() {
	int* p;
	//std::cout << p;// points to a garbage memeory.
	p = nullptr;//inmtializing pointer p to null pointer (nullptr) which points to nowhere
	std::cout << &p << std::endl; //Prints out the address
	std::cout << sizeof p << std::endl; //Prints out the size
	std::cout << p; //prints the value which is 0 sinze it is a null pointer.
}
*/
//Typed pointers:
//The compiler will make sure that the address stored in a pointer variable is of the correct type.
/*
int main() {
	int score{ 10 }; //Declaring a varibale and intializing it to 10.
	int* score_ptr{ nullptr }; //Declaring and intializing a pointer thjat points to null (0)
	score_ptr = &score;
	//score_ptr = &high_temp doing this will result of a compile erroe becasue you cannot assgin pointers to a different data types
	std::cout << "The value of scoreptr where in the address that pointing to " << *score_ptr << std::endl; // pointing to the value of score_ptr which is 10  since we assigned the pointer to the address of socre which now they share the same value
	std::cout << "The value of score" << score << std::endl; // printing out the value of score
	std::cout << "The address of score: " << &score << std::endl; //printing out the address of score
	std::cout << "The address where score_ptr has been assigned to " << score_ptr << std::endl; //printing out the address of score
	double high_temp{ 100.7 }; //Declaring a dobule and intializing a value to it.
	double* temp_ptr; //declaring a pointer
	temp_ptr = nullptr; //intialzing it to null (0)
	temp_ptr = &high_temp; //intializing temp_ptr to the address of high_temp
	std::cout << *temp_ptr << std::endl; //will print out the value which is 100.7
	std::cout << high_temp << std::endl; //will print out the value which is 100.7
	*temp_ptr = 50.7; //changing the value where temp_ptr points to which is high_temp
	std::cout << high_temp << std::endl; //printing out the result of high_tempwhixh is 50.7
	std::cout << temp_ptr << std::endl;
	std::cout << &high_temp << std::endl;
	/*
	Notes:
	1-Pointers are variables so they can chnage
	2-Pointers can be null
	*/

	//Derefrencing a pointer
	/*
	IF score_ptr is a pointer and has a valid address
	Then you can access the data atthe address containedin the score_ptr
	using the derefrencing operator. (*)
	*/
	/*
	int main() {
		int score{ 100 };
		int* score_ptr{ &score };

		std::cout << *score_ptr << std::endl; //will print out a 100.
		*score_ptr = 200; //assiging 200 to *score_ptr.
		std::cout << *score_ptr << std::endl;
		std::cout << score << std::endl;

		double high_temp{ 100.7 };
		double low_temp{ 37.4 };
		double* temp_ptr{ &high_temp };
		std::cout << *temp_ptr << std::endl;

		temp_ptr = &low_temp;
		std::cout << *temp_ptr << std::endl;

		std::string name{ "Frank"};
		std::string* string_ptr{ &name };//assigning string_ptr to the address of name string

		std::cout << *string_ptr << std::endl;

		*string_ptr = { "Billy" };

		std::cout << *string_ptr << std::endl;
		std::cout << name << std::endl;

		std::vector <std::string> stooges{ "Larry", "Moe", "Curly" };

		std::vector <std::string>* vector_ptr{ &stooges }; //assinging the vector_ptr to the address of stooges vector
		for (int i{ 0 }; i < 3; i++) {
			std::cou
			t << (*vector_ptr).at(i) << std::endl; //we use pernthisis becasue the dot has higher precedance there for we put the pernthisis so it points forst to the address then points to the place
		}
		for (auto stooges : *vector_ptr) {
			std::cout << stooges << std::endl;
		}
		std::cout << "First stooge: " << (*vector_ptr).at(0);

	}
	*/

	//Relationship between arrays and pointers
	/*
	The value of an array name is the address of the first element in the array
	the value of a pointer variable is an address
	if the pointer points to the same data types as the
	array element then the pointer and array name can be used interchnageably (Almost)
	*/
	/*
	int main() {
		int scores[]{ 100,95,89 };

		std::cout << scores << std::endl; //prints out the address of the array scores
		std::cout << *scores << std::endl; //prints out the first value in the array
		int*scores_ptr{ scores }; //we do not put the &when we aassign a pointer to an array address
		std::cout << scores_ptr[0] <<std::endl;//accessing the first element of an array which is 100
		std::cout << scores_ptr[1] << std::endl; //accessing the 2nd element of an array which is 95
		std::cout << scores_ptr[2] << std::endl; //accessing the 3rd element of an array which is 98

		std::cout << scores_ptr << std::endl; //the address of the first element inside and array
		std::cout << (scores_ptr + 1) << std::endl; //the address of the second element insideand array
		std::cout << (scores_ptr + 2) << std::endl; //the address of the third element inside and array

		std::cout << *scores_ptr << std::endl; //print out the valuie of the first element in the array
		std::cout << *(scores_ptr + 1) << std::endl; //prints out the second element
		std::cout << *(scores_ptr + 2) << std::endl; // prints out the 3rd element

		std::cout << *(scores + 1) << std::endl; //we can use it the same for the array as well...

		//Important notes

		Subscript and offset notation
		 int array_name [] {1,2,3,4,5};
		 int *pointer_name {array_name};

		 there is 2 ways to access the arrays data with pointers and array itself

		 1-Subscript Notation           A-array_name[index]
										B-Pointer_name[index]

		 2-Offset Notation              A- *(array_name + index)
										B- *(pointer_name + index)


		std::cout << "\nArray subscript notation-------------------------------" << std::endl;
		std::cout << scores[0] << std::endl;
		std::cout << scores[1] << std::endl;
		std::cout << scores[2] << std::endl;
		std::cout << "\nPointer subscript notation-------------------------------" << std::endl;
		std::cout << scores_ptr[0] << std::endl;
		std::cout << scores_ptr[1] << std::endl;
		std::cout << scores_ptr[2] << std::endl;
		std::cout << "\nPointer offset notation----------------------------------" << std::endl;
		std::cout << *scores_ptr << std::endl;
		std::cout << *(scores_ptr + 1) << std::endl;
		std::cout << *(scores_ptr + 2) << std::endl;
		std::cout << "\Array offset notation----------------------------------" << std::endl;
		std::cout << *scores << std::endl;
		std::cout << *(scores + 1) << std::endl;
		std::cout << *(scores + 2) << std::endl;


	}
	*/

	//Pointer Arithmetic
	//Pointers can be use in
	//            1-Assignment expressions
	//            2-Arithmetic expressions
	//            3-Comparison expressions
	//C++ allows pointer arithmetic
	//Pointer arithmetic only makes sense with raw arrays
	// ++ and --
	//(++) increment a pointer to point to the next array element
	//int_ptr++;
	// (--) decrements a pointer to point to the previous array element
	//int_ptr--;
	// + and -
	//(+) increment pointer by n * sizeof(type)
	// int_ptr += n;
	//(-) decrement pointer by n * sizeof(type)
	// int_ptr -= n;
	//Substracting two pointers
	//Determine the number of elements between the pointers
	//Both pointers must point to the same data type
	//int n = int_ptr - int_ptr1;

	//Comparing two pointers == and !=
	//     Does not compare the data where they point
	//Example 
	/*
	int main() {
		std::string s1{ "Frank" };
		std::string s2{ "Frank" };

		std::string* p1{ &s1 };
		std::string* p2{ &s2 };
		std::string* p3{ &s1 };
		std::cout << (p1 == p2) << std::endl; //False becasue p1 doesn't share the same address as p2
		std::cout << (p1 == p3) << std::endl; //True becasue p1 and p2 share the same address

	}

	*/
	//Comparing the data pointers to.
	//Determine if two pointers point to the same data
	//You must compare the referenced pointers
	 /*int main() {
			std::string s1{ "Frank" };
			std::string s2{ "Frank" };

			std::string* p1{ &s1 };
			std::string* p2{ &s2 };
			std::string* p3{ &s1 };
			//std::cout << (*p1 == *p2) << std::endl; //True. both of p1 and p2 share the same valuee Frank even if they are pointing to dofferent addresses
			//std::cout << (*p1 == *p3) << std::endl; // True. Same as p1 and p2
			int score[]{ 100,95,68,89,-1 };
			int* score_ptr{ score };
			while (*score_ptr != -1) { //loop before score_ptr is -1;
				std::cout << *score_ptr << std::endl;
				score_ptr++;

			}
			std::cout << "\n----------------------------------------\n";
			//another example is
			//you can increment the pointer in on line std::cout << *score_ptr++;
			//same as score_ptr++;
			 while (*score_ptr != -1) { //loop before score_ptr is -1;
				std::cout << *score_ptr++ << std::endl;
			}

			 char name[]{ "Frank" };
			 char* char_ptr1;
			 char* char_ptr2;

			 char_ptr1 = &name[0];
			 char_ptr2 = &name[3];

			 std::cout << "In the string " << name << ", " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1 << std::endl;


	}

	*/

	//Passing pointers to ba function
	//Const and pointers
	//There are several ways to qualify pointers using const.
						//1-pointer to constants
						//2-Constant pointers
						//3-Constant pointers to constants


	//1-Pointers to constants

	//The data pointed to by the pointers is constant and cannot be changed
	//The pointer itself can chnage and point somewhere else 

	/*
	int main() {
		int high_score{ 100 };
		int low_score{ 65 };
		const int* score_ptr{ &high_score }; //value of high_score cannot be chnaged in *score-ptr
		//*score_ptr = 86 == compiler error
		score_ptr - &low_score;



	}

	*/


	//2-Constant pointers
	//The data pointed to by the pointers can be chnaged
	//The pointer itself cannot change and point somewhere else
	/*

	int main() {
		int high_score{ 100 };
		int low_score{ 65 };
		int* const score_ptr{ &high_score }; //you can chnage the value inside the high_temp
		std::cout << *score_ptr << std::endl;
		*score_ptr = 90;
		std::cout << *score_ptr;
		//score_ptr = &low_score == you will get a compile error since you can chnage where score_ptr points to since it is Constant pointer

	}
	*/
	//3-Constant pointers to constant
	//The data pointed to by the pointer is constant and cannot be chnaged
	//The pointer itself cannot change and point somewhere else
	/*
	int main() {
		int high_score{ 100 };
		int low_score{ 65 };
		const int* const score_ptr{ &high_score };

		*score_ptr = 86 // error
		score_ptr = &low_score; //error
	}
	*/
	//Passing pointers to a function
	//Pass by refrence with pointer parameters
	//we can use pointers and the dereference operator to achieve pass-by-refrence
	//The function parameter is a pointer
	//The actual parameter can be a pointer or address of a variable

	/*
	//Example 1
	int double_data(int* int_ptr) {

		*int_ptr *= 2;
		return *int_ptr;
	}
	int main() {
		int a{ 4 };
		int* point{ &a };
		std::cout << "Address of a: " << &a << std::endl;//printing out the address of a
		std::cout << "Address where point is pointing to: " << point << std::endl;//Printing out the address where point points to which is the address of a

		std::cout << "Value: " << double_data(point) << std::endl;//When passing a pointer to aa function parameter we do not put the (*) beause we are passing by reference
		std::cout << "Value: " << double_data(&a) << std::endl;;//you can also pass-by-refrence with the variable
		std::cout << "Value: " << double_data(point) << std::endl;
		std::cout << "Value: " << a << std::endl;
		std::cout << "Value: " << *point << std::endl;

	}


	//Example 2

	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;

	}
	int main() {
		int x{ 100 };
		int y{ 200 };
		int* int_ptr1{ &x };
		int* int_ptr2{ &y };

		 swap(&x, &y);//passing by refrence
		 std::cout << x << std::endl;//200
		 std::cout << y << std::endl;//100
		 swap(int_ptr1, int_ptr2); //passing with pointers
		 std::cout << *int_ptr1 << std::endl;//100
		 std::cout << *int_ptr2 << std::endl;//200
	}


	//Example 3
	void display(std::vector <std::string>* v) {
		(*v).at(0) = "Funny";//changing where the first value of the vector to funny
		for (auto str : *v)
			std::cout << str << " ";


	}
	void display(int* array, int sentinel) {
		*array= 6;//changing the first value of the array 6
		while (*array != sentinel) { //looping through the array
			std::cout << *array++ << " ";
		}
	}

	int main() {
		std::vector <std::string> stooges{ "larry", "Moe", "Curly" };
		display(&stooges);
		int array[]{ 1,2,3,4,6,7,80,7,6,9 };
		display(array, 9);
	}
	*/


	//Returning a pointer from a function
	//type *function();
	//Should return pointers to
	//Memeory dinamically allocated in the function
	//to data that was passed in 
	//Never return a pointer to local function variable.
	/*
	int *dont_do_this(){
	int size{};
	return &size; do not do this
	}
	int *or_this(){
	int size{};
	int *int_ptr{&size};

	return int_ptr; do not do this also
	}



	int* largest_int(int* int_ptr1, int* int_ptr2) {
		if (*int_ptr1 > * int_ptr2) {
			return int_ptr1;//we return with no *
		}
		else {
			return int_ptr2;//We return with no *
		}
	}


	int main() {
		int x{ 9 };
		int y{ 8 };
		int* pp{ &x };
		int* bb{ &y };
		std::cout << *largest_int(&x, &y);//passing by refrence
		std::cout << *largest_int(pp, bb);//passing with pointers
		delete[] pp;
		delete[] bb;

	}

	//Potential pointer pitfalls
	//Unintialized pointers
	//dangling Pointers
	//Not chcecking if new failed to allocate memeory
	//Leaking memepry

	//1- Unintialized pointers
	///int *int_ptr; //Pointing anywhere
	// *int_ptr = 100; //Hopefully a crash


	//2-dangling Pointers
	//Pointers that is pointing to releasec memeory
	//For example, 2 pointers point to the same data
	//1 pointer releases the data with delete
	//The other pointer acesses the release data

	//Pointer that points to a memeory that is invalid
	//We saw this when we returned a pointer to a function local variable


	//3-Not chcecking if new failed to allocate memeory
	//If "new" fails and exception is thrown
	//We can use exceptions handling to catch exceptions
	//Derefrencing a null pointer will casue your program to crash



	//4-Leaking memory
	//Forgetting to release allocated memory with delete
	//if you lose your pointer to the storage alllocated on the heap you have not way to get that storage again
	//The memeory os orphaned or leaked
	//One of the most common pointer problems


	//What is areference

	//1-An alias for a variable
	//2-Must be intialized to a variable when declared
	//3-Cannot be null
	//4-Once intialized cannot be made to refer to a different variable
	//5-Very useful a function parameters
	//6-Might be helpful to think of a reference as a constant pointer that is automatically derefernced

	int main() {
		std::vector <std::string> stooges{ "Larry", "Moie", "Curly" };

		for (auto &str : stooges) {//if we put the reference & on str it will save the outcome if we call the vector outside of this loop and chnage the vector elements
			//str = "Funny"; //chnages the copy byt doesn't chnage the out come of the vector when we loop with another loop
			//std::cout << str << std::endl;// will print out funny 3 times
		}
		for (auto str : stooges) {
			//std::cout << str << std::endl; //larry,Moe,curly
			//since we have & int str hen it will display funny 3 times
		}
		for (auto const& str : stooges) {
			//str = "Funny"; //this will present compile erroe since str is const
			//std::cout << str << std::endl;
		}

		//using alias

		int num{ 100 };
		int& ref{ num }; //using alias ref to assign it to num
		std::cout << num << std::endl;
		std::cout << ref << std::endl;
		ref = 200;
		std::cout << num << std::endl;
		std::cout << ref << std::endl;
	}

	*/

	//L-values and R-values

	//l -values
	//Values that have names and are addressable
	//Modifiable if they are not constants

//int main() {
	//l-value:
	//int x{ 100 }; //x is an l-value
	//x = 1000;
	//x = 1000 + 20;

	//std::string name{ "Frank" }; //name is an l-value
	//name = "Lowey";
	//100 = x;// 100 is not an l-value
	//(100 + 20) = x; //100 +20 is not an l-value
	//std::string name2;
	//name = "Frank";
	//"Franky" = name; //"frank is not an l-value"




	//r-value:
	//1-r-value(non addressable and non assignable)
	//avalue that is not an l-value
	/*
	on the right hand of an assignment expression
	a literal
	a temporary which is intended to be non-modifiable
	*/
	//int x{ 100 }; //100 is an r-value
	//int y = x + 200; //(x+200) is an r-value
	//std::string name;
	//name = "Frank"; //Frank is an r-value
	//int max_num = max(20, 30); max(20,30) is an r-value.
	//r-value can be assigned to l-value explicitly
	//int x{ 100 };
	//int y{ 0 };
	//y = 100; //r-value 100 is asigned to l-value y
	//x = x + y; //r-value (x+y) assigned to l-value
	//the references we've used are l-value refences; because we are referencing l-values
	//int x{ 100 };
	//int& ref = x; //ref is reference to l-value
	//ref = 1000;
	//int& ref2 = 200; error 200 is an r-value
	//The same applies when we pass-by-reference
	/*
	int square(int& n) {
	return n*n;
}
int num{10};
square(num) is ok
square(5) Error-cannot refernce r-value 5
	*/




	//Section recap

	//When to use pointers vs reference parameters
	/*
	Pass by value:
		When a function does not modify the actual parameter and
		the parameter is small and efficent to copy like simple types(int,char,double,etc..)
	Pass-by-reference using a pointer
		When a function does modify the actual parameter,
		and the parameter is expensive to copy
		and it ok to the pointer is allowed a nullptr value
	pass-by-reference using a pointer to CONST
		When the function does not modify the actual parameter,
		and parameter is expensive to copy,
		and it is OK to the pointer is allowed a nullptr value
	pass-by-refernce using a const pointer to const
		When the function does not modify the actual parameter,
		and the parameter is expensive to copy,
		and it is ok to the pointer is allowed a nullptr value,
		and you don't want to modify the pointer itself
	pass-by-reference using a reference
		when the function does modify the actual parameter,
		and the parameter is expensive to copy
		and the parameter will never nullptr
	pass-by-reference using a const refernece
		when the function does not modify the actual parameter,
		and the parameter is expensive to copy
		and the parameter will never be nullptr

	*/

	///////////////////////////OBJECT ORIENTED PROGRAMMING Data structures and Algorithms in C++ ///////////////////////////////////////
	//Safely using Arrays
#include <array>
//Built in Arrays Allocations: Stack VS Heap.
//Dynamic memory allocation
/*
int main() {
	int* array_ptr{nullptr};
	int size{};
	std::cout << "How big do you want the array\n";
	std::cin >> size;
	array_ptr = new int[size];//This allocate memory on the heap
	std::cout << array_ptr;//shows the address of this pointer on the heap
	delete[] array_ptr;//Clears the heap


	double size{0};
	double* tmp_ptr;
	std::cout << "How many tmps";
	std::cin >> size;
	tmp_ptr = new double[size];
	std::cout << tmp_ptr << std::endl;
	delete[] tmp_ptr;//Release Memeory on the heap
}
*/

//Implementing a last-in first-out pattern with the stack
//Stack implementation
/*
int lienarS(int element, const int* v, int size) {
	for (int i = 0; i < size; i++) {
		if (v[i] == element) {
			return i;
		}
	}
}
void print(std::vector <int>* v) {
	for (auto l : *v) {
		std::cout << l << " ";
	}
}
int main() {
	std::vector <int> v = { 1,2,3,4,7,88,99 };
	print(&v);
	int x;
	std::cout << "Enter the element you want to search it's index\n";
	std::cin >> x;
	int pos = lienarS(x, v.data(), v.size());
	std::cout << pos << std::endl;
}
*/





