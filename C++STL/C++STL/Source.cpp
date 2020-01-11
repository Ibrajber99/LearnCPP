#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include <conio.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <time.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <memory>
#include <cstring>
#include <locale> 
#include <sstream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <ostream>
#include<fstream>
#include <windows.graphics.h>
#include <istream>
#include <utility>
#include <array>
#include<set>
#include<map>
#include<list>
#include<iterator>
#include<forward_list>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <numeric>

/*
								C++ Standard Template library (STL)		
			Section Overview
	What is STL
	Generic Porgramming/Meta-programming
	Preprocessor macros
	Function templates
	Class templates
	STL Containers
	STL iterators
	STL algorithms
	Array
	Vector
	Deque
	List and Forward list
	Set and multiset
	Map and Multi Map
	Stack and queue
	Priority Queue
	Algorithms
--------------------------------------------------------------------------------------
								What is the STL?
A library of powerful,reusable,adaptable,generic classes and functions,
Implemented using C++ templates
Implement common data structures and algorithms
Huge class library!!
Created by-> Alexander Stepanov(1994)
--------------------------------------------------------------------------------------
								Benefits of using the STL
Assortment of commonly used containers
Know time and size complexity-> bigO
Tried and tested - Reusability
Consistant, fast,and type-safe
Extensible
--------------------------------------------------------------------------------------
								Elements of the STL
Constainers
	Collections of objects or primitive types
		(array,vector,deque,stack,set,map,etc)
Algorithms
	Functions for processing sequences of elements from containers
		(find,max,count,accumulate,sort,etc)
Iterators
	Generate sequences of element from containers
		(forward,reverse,by value,by reference,constant,etc)
--------------------------------------------------------------------------------------
		A simple example-sort a vector
		std::vector<int> v {1,5,3};
		std::sort(v.begin(),v.end());
		for(auto elem: v)
			std::cout << elem << std::endl;  // 1 3 5

		A simple example-reverse a vector
			std::vector<int> v {1,5,3};
			std::reverse(v.begin(),v.end());
			for(auto elem: v)
			std::cout << elem << std::endl;  // 5 3 1

		A simple example-accumulate
			int sum{};
			sum = std::accumulate(v.begin(),v.end(),0)-> the 0 is from where should the count start
			std::cout << sum; // 1+3+5 = 9
--------------------------------------------------------------------------------------
								Types of Containers
Sequence containers
	array,vector,list,forward_list,deque

Associative containers
	set,multi set,map,multi map

Container adapters
	stack,queue,priority queue
--------------------------------------------------------------------------------------
								Types of iterators
Input iterators- from the container to the program
output iterators- from the program to the container
Forward iterators- navigate one item at a time in on direction
Bi-directional iterators- navigate one item at a time both directions
Random access iteratos- directly access a container item
--------------------------------------------------------------------------------------
								Types of Algorithms
About 60 algorithms in the STL
Non-modifying
Modifying
--------------------------------------------------------------------------------------
								Generic programming with macros
Generic programming:
	"Writing code that works with a variety of types as arguments as long as those argument types
	meet specific syntatic semantic requirements", Bjarne Stroustrup

Macros ***Beware***
Function templates
Class templates

Macros(#define)
C++ preprocessor directives
No type information
Simple substitution
	#define MAX_SIZE 100
	#define PI 3.1459

	if(num > MAX_SIZE)
		std::cout << "NUM IS BIGGER THAN MAX_SIZE";
		double area = PI *r *r;

this results to removing the convetions under the hood and grabs the values

	if(num > 100)
		std::cout << "NUM IS BIGGER THAN MAX_SIZE";

		double area = 3.1459 *r *r;

max Function
	int max(int a, int b){
		return (a > b) ? a : b;

	}
	int x = 100;
	int y = 200;
	std::Cout << max(x,y); //displays 200

-----Now suppose we need to determine the max of 2 doubles and 2 char
	The normal approach gonna be creat different signtures fro the function:

	double max(int a, int b){
		return (a > b) ? a : b;

	}
	char max(int a, int b){
		return (a > b) ? a : b;

	}
	BUT!!----> we can write generic macros with arguments instead

	# define MAX(a,b) ((a > b) ? a : b)
	std::cout << MAX(5,8) << std::endl; //8
	std::cout << MAX(2.4,3.5) << std::endl; //3.5
	std::cout << MAX('A','C') << std::endl; //C

	!!We have to be careful with macros
	#define SQUARE(a) a*a

	result = SQUARE(5); //Expect 25
	result = 5*5   //get 25

	result = 100 / SQUARE(5); //Expect 4
	result = 5*5   //get 100

	SO......
	always have parenthesis otherwise the order of evaluation will be missed up

	#define SQUARE(a) ((a)*(a)) //NOTE the parenthesis

	result = SQUARE(5); //Expect 25
	result = ((5)*(5))   //get 25

	result = 100 / SQUARE(5); //Expect 4
	result = ((5)*(5))    //NOW we get 4
--------------------------------------------------------------------------------------
Generic programming with function templates
What is C++ template?
	BluePrint
	Function and class templates
	Allow pluggin-in any data-type
	Compiler generates the appropriate function/class from the blueprint
	Generic programming/ meta-programming

	--Let's revisit the max function from last section

	int max(int a,int b){
		return (a > b) ? a: b;
	}
	std::cout << max(5,6); //6

	Now if we want to determin the max of 2 double or 2 chars
	That's when Generic programming cimes in place

	--We can replace type we want to generalize with a name, sy T
	But now this won't compile

	T max(T a, T b){
		return (a > b) ? a:b;
	}

	--So....
	We need to tell the compiler this is a template function
	We also need to tell that T is the template parameter

	template <typename T>
	T max(T a, T b){
		return (a > b) ? a:b;   //This would work!!
	}
	We may also use class instead of typename
	template <class T>
	T max(T a, T b){
		return (a > b) ? a:b;   //This would work!!
	}

	--
	Now the compiler can generate the appropriate function from the template
	Note, this happens at compile-time!

	int a{10};
	int b{20};
	std::cout << max<int>(a,b);

	--
	Many times the compiler can deduce the type and the template parameter is needed
	Depending on the type of a and b, the compiler will figure it out

	std::cout << max<double>(c,d);
				you can do this not alwasy but in majority of cases
	std::cout << max(c,d);
	--
	Notice the type MUST support operator > either natively or as an overloaded operator(operator>)

	We can have multiple template parameters
	And their types can be different

	template<typename T1, typename T2>
	void func(T1 a,T2 b){
		std::cout << a << " " << b;
	}
	When we use the function we provide the template parameters
	Often the compiler can deduce them

	func<int,double>(10,20.2);
	func('A',12.4);

	Code example to sum up function templates:


	template <typename T>
T minX(T a, T b) { //generic programming
	return(a < b) ? a : b;
}



class Person {
public:

	std::string name;
	int age;
	bool operator<(const Person& rhs) const {//we need an overloaded operator to tell the template func what to compare exactly
		return this->age < rhs.age;
	}

};
 std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name;
	return os;
}

 template <typename T1, typename T2>
 void func(T1 a, T2 b) {
	 std::cout << a << " " << b;
 }

int main() {

	Person p1{ "Larry",34 };
	Person p2{ "Moe",55 };


	Person p3 = minX(p1, p2);
	std::cout << p3.name << std::endl; //larry
	func(p1, p2); //larry moe since we have exraction overloaded operator std::ostream
	std::cout << std::endl;

	std::cout << minX<int>(2, 3) << std::endl; //2
	std::cout << minX(2, 3) << std::endl; //2
	std::cout << minX('A', 'B') << std::endl; //A
	std::cout << minX(12.5, 3.8) << std::endl; //3.8
	std::cout << minX(5+2*2, 7+40) << std::endl;//9

	func<int,int>(10, 20);
	func(10, 20);
	func<char,double>('A', 2.78);
	func('A', 2.78);
	func(1000, "Testing");
	func(200, std::string{"Frank"});
--------------------------------------------------------------------------------------
								Generic Programming with class templates
WHat is C++ class template?
	Similar to function template, but at the class level
	Allows plugging-in any data type
	Compiler generates the appropriate class from from the blueprint

	Let's say we want a class to hold items where the items has a name and an integer

	class Item{
	private:
		std::string name;
		int value;
	public:
		item(std::string name,int value)
			:name{name},age{age} {}

		std::string getName()const {return name;}

		int getValue()const {return age;}
	}
	But we'd like our Item class to be able to hold any type of data in addition to the string
	Wecan;t overload class names
	We don't want to use dynamic polymorphism

	--Therefore!!

	we can use class templates

	template <typename T>
	class Item{
	private:
		std::string name;
		T value;
	public:
		Item(std::string name,T value): name{name},value{value} {}

		std::string getName() const{return name;}
		T getValue() const {return value;}
	
	}
	Item<int> item1 {"Larry",1};
	Item<double> item1 {"Larry",2.9};
	Item<std::string> item1 {"Larry","Hey"};
	std::vector<Item<int>>vec;
--------------------------------------------------------------------------------------
								Multiple types as template parameters
We can have multple parameters
And their types can be different

	template<typename T1,typename T2>
	struct My_pair{
		T1 first;
		T2 second;
	};
	My_pair <std::string,int>p1 {"Frank",100};
	My_pair <int,double>p2 {12,9.78};
	std::vector<Item<int,doube>>vec;

								std::pair
#include<utility>
std::pair<std::string,int>p1{"Frank",100};
std::cout << p1.first; //Frank
std::cout << p1.second; //100
		
		Code example of the section on top


template <typename T>

//Template classes are typically completely contained in header files
//So,we would have the template class in Item.h not in Item.cpp
//Would be used

class Item {
private:
	std::string name;
	T value;

public:
	Item(std::string name,T value):name{name},value{value}{}
	std::string getName()const { return name; }
	T getValue()const { return value; }
};
template <typename T1,typename T2>
struct My_pair {
	T1 first;
	T2 second;
};

int main() {
	Item<int> item1{ "Frank",100 };
	std::cout << item1.getName() << " " << item1.getValue() << std::endl;

	Item<std::string> item2{ "Frank","Professor" };
	std::cout << item2.getName() << " " << item2.getValue() << std::endl;

	Item<Item<std::string>>item3{ "Frank",{"C++","Professor"} };
	std::cout << item3.getName() << " " << item3.getValue().getName() << "  " << item3.getValue().getValue() << std::endl;

	std::vector<Item<double>>vec{};
	vec.push_back(Item<double>("Larry", 100.0));
	vec.push_back(Item<double>("Moe", 200.0));
	vec.push_back(Item<double>("Curly", 300.0));

	for (const auto &i : vec) {
		std::cout << i.getName() << " " << i.getValue() << std::endl;
	}

	My_pair <std::string, int>p1{ "Frank",100 };
	My_pair <int, double>p2{ 12,100.0 };

	std::cout << p1.first << " " << p1.second << std::endl;
	std::cout << p2.first << " " << p2.second << std::endl;
}
--------------------------------------------------------------------------------------
//Class template Array
//Note: Since C++ 11 the STL has std::array which is a template-based array class
//Use std::array instead of raw array whenever is possible
//Note that we can have non type template peramters
//That is what N is in this case

template <typename T,int N>
class Array {
	int size{ N };
	T values[N]; //The N need to be knoe at compile time

	friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {
		os << "[";
		for (const auto& val : arr.values) {
			os << val << " ";

		}
		os << "]" << std::endl;
		return os;
	}

public:
	Array() = default;
	Array(T initVal) {
		for (auto& item : values)
			item = initVal;
	}
	void fill(T val) {
		for (const auto &item : values) {
			item = val;
		}
	}
	int getSize()const { return size; }

	//Overloaded subscript operator for easy use
	T& operator[](int index) {
		return values[index];
	}


};


int main() {
	Array<std::string,9>p1("Frank");
	std::cout << p1 << std::endl;
	std::string s = { "Ibrahim" };
	Array<std::string, 9>p2("Ibrahim");
	std::cout << p1 << std::endl;
	std::cout << p1 << std::endl;

}
-----------------------------------------------------------------------------------
								Containers
Data Structures that can store object of almost anytype
	Template-Based classes
Each container has memmber functions
	Some are specific to the container
	Others are available to all containers
Each container has an associated header file
	#include <container_type>

What types of elements can we store in Containers>

A copy of the element will be stored in the container
	All primitives OK
Element should be
	Copyable and assignable (Copy constructor/copy assignment)
	Moveable for efficiency (move constructor / move assignment)

ordered associative containers must be able to compare elements
	operator <, operator==
-----------------------------------------------------------------------------------
								Iterators		
Allows abstracting an arbitrary container as a sequence of elements
They are objects that work like pointers by design
Most container classes can be traversed with iterators

Declaring Iterators
	Iterators must be declared based on the container type
		std::vector<int>::iterator it1;
		std::list<std::string>iterator it2; 
		std::map<std::string,std::string>iterator it4; 
		std::set<char>iterator it4; 
Iterators begin and end methods
	std::vector<int>vec {1,2,3};
	vec.begin()-> = vec.at(0)-> 1
	vec.end()-> location after last element ->	NULL

	std::set<char>suits {'C','H','S','D'};

	set data are not stored in contigious memory
	sutie.begin()->C
	suits.end()->NULL

Using iterators- std::vector
	std::vector<int>vec {1,2,3};
	std::vector<int>::iterator it = vec.begin();

	while(it != vec.end()){
		std::cout << *it << " ";
		++it;
	}// 1 2 3

	Range based iteration for loop
	for(auto it = vec.begin(); it != vec.end(); it++){
		std::cout << *it << " ";
	}//1 2 3
	Using iterators- std::set
	std::set<char> suits {'C','H','S','D'};

	auto it = suits.begin();

	while(it != suits.end()){
		
		std::cout << *it << "  " << std::endl;
	++it;
	}
-----------------------------------------------------------------------------------
Reverse iterators

Wroks in reverse
Last element is the first and first is the last
++ moves backward, -- movesforward

std::vector<int> myvector{1,2,3,4,5};
	std::vector<int>::reverse_iterator it = myvector.rbegin();
	while (it != myvector.rend()) {
		std::cout << *it << "  ";
		it++;
	}
	//5 4 3 2 1

	Other iterators
		begin() and end()
			iterator
		cbegin() and cend()
			const_iterator
		rbegin(), rend()
			reverse_iterator
		crbegin(), crend()
			const_reverse_iterator
-----------------------------------------------------------------------------------
Iterators code demonstration
//display vector of integers using range base for loop
void display(const std::vector<int>& vec) {
	std::cout << "[";
	for (const auto& it : vec) {
		std::cout << it << "  ";
	}
	std::cout << "]" << std::endl;
}

void test1() {
	std::vector<int>nums1{ 1,2,3,4,5 };
	auto it = nums1.begin();
	std::cout << *it << std::endl; //points to 1

	it++;
	std::cout << *it << std::endl; //points to 2

	it += 2;
	std::cout << *it << std::endl; //points to 4

	it = nums1.end() - 1; // point to 5

	std::cout << *it << std::endl;

}
void test2(){
	std::vector<int>vec{ 1,2,3,4,5 };
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << "  ";
		it++;
	}
	//change all elements to 0
	it = vec.begin();
	while (it != vec.end()) {
		*it = 0;
		it++;
	}
	display(vec);

}
void test3() {
	//using a const iterator
	std::vector<int>vec{ 1,2,3,4,5 };
	std::vector<int>::const_iterator it = vec.cbegin();
	for (; it != vec.cend(); it++) {
		//*it = 0;->won't compile since it is aconst iterator
		std::cout << *it << " ";
	}
}


void test4() {
	//More iterators
	//using a reverse iterator
	std::vector<int> vec{ 1,2,3,4 };
	auto iter = vec.rbegin();
	while (iter != vec.rend()) {
		std::cout << *iter << "  ";
		iter++;
	}
	std::cout << std::endl;

	//const reverse iterator over a list
	std::list<std::string>list1{ "Ibra","Abd","Yousef" };
	std::list<std::string>::const_reverse_iterator it = list1.crbegin();

	for (auto it : list1) {
		std::cout << it << "  ";
	}
	std::cout << std::endl;

	std::map<std::string, std::string> favorites{
		{"Ibra","C++"},
		{"Abd","Python"},
		{"Yousef","GDM"}
	};
	std::map<std::string, std::string>::iterator iter2 = favorites.begin();
	while (iter2 != favorites.end()) {
		std::cout << iter2->first << "  "<<iter2->second;
		iter2++;
	}
	std::cout << std::endl;
}

void test5() {
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	auto start = vec.begin();
	auto finish = vec.end();
	while (start != finish) {
		std::cout << *start << "  ";
		start++;
	}
	std::cout << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
}
-----------------------------------------------------------------------------------
								Algorithms
STL algorithms work on dequences of container elements provided to them by an iterator

STL has many coomon and useful algorithms

Too many to describe in here
	reference: http://en.cppreference.com/w/cpp/algorithm

Many algorithms require extra information in order to do their work
	Functors(function objects)
	Function pointers
	Lambda expressions(C++11)

Algorithms
#include <algorithm>

Different containers support different types of iterators
	Determines the types of algorithms supported

All STL algorithms expect iterators as arguments
	Determines the sequence obtained from the container

Suppose we are iterating over a sector of 10 elements
	And we clear() the vector while iterating?what happens?
	Undefined behavior- our iterators are pointig to invalid locations
-----------------------------------------------------------------------------------
Example algorithms find with primitive types
The find algorithm tries to locate the first occurence of an element in a container
Lots of variations
Reurns and iterator pointing to the located element or end()

std::vector<int> vec {1,2,3};

auto it = std::find(vec.begin(),vec.end(),3)--->we want to search for 3 in the vector

if(it != vec.end()){
	std::cout << *it << std::endl; //3
}
-----------------------------------------------------------------------------------
Example algorithm - find with user-defined types
Find needs to be able to compare object
	operator== is used and must be provided by your class

	std::vector<Player>team {assum it is intialized}
	Player P {"Hero",100,12};
	auto loc = std::find(vec.begin();team.end();p);

	if(loc != vec.end()){ //found it
		std::cout << *loc; //then operator << is called
	}
-----------------------------------------------------------------------------------
Example algorithm - for_each

for_each algorithm applies a function to each element in the iterator sequence

Function must be provided to the algorithm as:

Functor(function object)
Function pointer
Lambda expression(C++11) feature

Let's square each element for instance
-----------------------------------------------------------------------------------
for_each using a functor
	
	struct Square{
		void operator()(int x){ //overload operator ()
			std::cout << x *x << std::endl;
		}
	}
	Square square1; //Function object

	std::vector<int> vec{1,2,4,6};
	std::for_each(vec.begin(),vec.end(),square1);
	// 1 4 9 16
-----------------------------------------------------------------------------------
for_each -using a function pointer

	void square(){
	std::cout << x * x << " ";
	
	}
	std::vector<int>vec {1,2,3,4};

	std::for_each(vec.begin(),vec.end(),square)
	// 1 4 9 16
-----------------------------------------------------------------------------------
for_each -using lambda expression
	
	std::vector<int> vec {1,2,3,4};
	std::for_each(vec.begin(),vec.end(),[](int x){
	std::cout << x * x << "  "; //lambda
	})
	// 1 4 9 16
-----------------------------------------------------------------------------------
code Example for the Algorithms Section

class Person {
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name,int age):name{name},age{age}{}
	bool operator<(const Person& rhs)const { //Overloaded operator
		return this->age < rhs.age;
	}
	bool operator==(const Person& rhs)const {//Overloaded operator
		return this->name == rhs.name && this->age == rhs.age;
	}
	friend std::ostream& operator<<(std::ostream &os, Person& rhs) {//Overloaded operator
		os << "Name is: " << rhs.name << " Age is: " << rhs.age;
		return os;
	}
};
void findTest() {
	std::vector <int> vec{ 1,2,3,4,5 };
	auto loc = std::find(std::begin(vec), std::end(vec), 4);
	if (loc != vec.end()) {
		std::cout << "Element found: " << *loc << std::endl; //4
	}
	else {
		std::cout << "Element is not found\n";
	}
	std::list<Person>players{
		{"Larry",18},
		{"Moe",20},
		{"Curly",90}
	};
	auto loc1 = std::find(players.begin(), players.end(), Person{ "Larry",18 });
	if (loc1 != players.end()) {
		std::cout<<"The Found Element in Persons is: " << *loc1 << std::endl;//print out Person object based on the extraction operator
	}
	else {
		std::cout << "Element is not found\n";
	}


}
void countTest() {
	std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
	int num = std::count(vec.begin(), vec.end(), 1);
	std::cout << num << " Occurrences found " << std::endl;
}
void count_if_Test() {
	std::vector<int>vec{ 1,2,3,4,5,1,2,1,100 };
	int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; });
	std::cout << num << " Even numbers found\n";
	num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0; });
	std::cout << num << " Odd numbers found\n";

	num = std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5; });
	std::cout << num << " Elementsgreater than five found\n ";
}
void replace() {
	std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
	for (const auto& it : vec) {
		std::cout << it << "  ";
	}
	std::cout << std::endl;
	std::replace(vec.begin(), vec.end(), 1, 300);
	for (const auto& it : vec) {
		std::cout << it << "  ";
	}
	std::cout << std::endl;
}
void all_of_Test() {
	std::vector<int> vec{ 1,3,5,7,9,1,3,13,19,15 };
	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10; })) {
		std::cout << "All the Elements are > 10" << std::endl;
	}
	else {
		std::cout << "Not all elements are greater than 10\n";
	}
	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x < 20; })) {
		std::cout << "All the Elements are < 20" << std::endl;
	}
	else {
		std::cout << "Not all elements are less than 20\n";
	}

}

void transformString() {
	std::string str{ "This is a Test" };
	std::cout << "Before transform " << str << std::endl;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << "After Transform " << str << std::endl;
}

int main() {
	findTest();
	}
-----------------------------------------------------------------------------------
								Sequence containers std::array
	std::array (C++11)
	#include <array>
	
	Fixed size
		Size must be know at compile time
	
	Direct element access
	
	Provides access to the underlying raw array
	
	Use instead of raw arrays when possible
	
	All iterators available and do not invalidate
-----------------------------------------------------------------------------------
								std::array intialization and assignment
	std::array <int,5> arr1 {1,2,3,4,5};
	
	std::array<std::string,3> stooges {"Moe","Larry","Curly"};
	
	arr1 = {2,4,6,8,10};
-----------------------------------------------------------------------------------
								std::array common methods
	std::array <int,5> arr1 {1,2,3,4,5};
	std::array <int,5> arr2 {10,20,30,40,50};

	std::cout << arr.size(); //5

	std::cout << arr.at(0);//1
	std::cout << arr[1]; //2

	std::cout << arr.front(); //1
	std::cout << arr.back(); //5
-----------------------------------------------------------------------------------
								std::array common methods

	std::array <int,5> arr {1,2,3,4,5};
	std::array <int,5> arr2 {10,20,30,40,50};

	std::cout << arr.empty(); // 0 false
	std::cout << arr.max_size(); // 5

	std::cout << arr.fill(10); //It will fill all the indexes with 10 instead
	arr.swap(arr2) // swaps the 2 arrays

	int *data = arr.data(); //get raw array address
-----------------------------------------------------------------------------------
								code examples of std::array section


void display(std::array<int, 5>& arr) {
	std::cout << std::setw(10);
	std::cout << "[";
	for (auto it = arr.begin(); it != arr.end(); it++) {
		std::cout << *it << "  ";
	}
	std::cout << "]";
	std::cout << std::endl;

}
void test1() {
	std::array<int, 5>arr1{ 1,2,3,4,5 };
	std::array<int, arr1.size()>arr2;

	display(arr1);
	display(arr2);
	arr2 = { 10,20,30,40,50 };
	display(arr1);
	display(arr2);
	std::cout << "Size of arr1: " << arr1.size() << std::endl;
	std::cout << "Size of arr2: " << arr2.size() << std::endl;

	arr1[0] = 1000;
	arr1.at(1) = 2000;
	display(arr1);

	std::cout << "front of arr2: " << arr1.front() << std::endl;
	std::cout << "back of arr2: " << arr2.back() << std::endl;

}
void test2() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 1,2,3,4,5 };
	std::array<int, arr1.size()>arr2{ 10,20,30,40,50 };

	display(arr1);
	display(arr2);

	arr1.fill(0); // fillin all the elments with 0 instead

	display(arr1);
	display(arr2);

	arr1.swap(arr2);
	display(arr1);
	display(arr2);

}
void test3() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 1,2,3,4,5 };

	int* arr_ptr = arr1.data();
	std::cout << *arr_ptr << std::endl;
	arr_ptr[1] = 1000;

	display(arr1);
}
void test4() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 2,1,5,3,4 };

	display(arr1);

	std::sort(arr1.begin(), arr1.end()); //sorting algorithm

	display(arr1);

}
void test5() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 2,1,5,3,4 };

	std::array<int, arr1.size()>::iterator minA = std::min_element(arr1.begin(), arr1.end());
	std::array<int, arr1.size()>::iterator maxA = std::max_element(arr1.begin(), arr1.end());
	std::cout << "The min element is: " << *minA << " The max Element is: " << *maxA << std::endl;

}
void test6() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 2,1,3,3,4 };

	auto adjecant = std::adjacent_find(arr1.begin(), arr1.end());
	if (adjecant != arr1.end()) {
		std::cout << "Adjacent element found with value: " << *adjecant << std::endl;
	}
	else {
		std::cout << "No Adjacent element found\n";
	}
}
void test7() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 2,1,3,3,4 };

	int num = std::accumulate(arr1.begin(), arr1.end(),0);
	std::cout << "The sum of all elements in the array: " << num << std::endl;
}
void test8() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 5>arr1{ 4,1,3,4,4 };

	int num = std::count(arr1.begin(), arr1.end(), 4);
	std::cout << "Found: " << num << " times \n";
}
void test9() {
	std::cout << "----------------------------------------------------\n";
	std::array<int, 10>arr1{ 1,2,3,50,60,70,80,200,300,400 };

	int count = std::count_if(arr1.begin(), arr1.end(), [](int x) {return x > 10 && x < 200; });
	std::cout << "Found: " << count << " Matches\n ";

}
int main() {

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}
-----------------------------------------------------------------------------------
								std::vector
#include <vector>

	Dynamic size
		Handeled automatically
		Can expand and contract as needed
		Elements are stored in contigious memory as an array
	
	Direct element access(constant time)

	Rapid insertion and deletion at the back (constant time)

	Insertion or removal of elements(linear time)

	All iterators available and may invalidate

std::vector

	std::vector<int> vec {1,2,3}
	vec.front()-> the first element
	vec.back()-> last element
-----------------------------------------------------------------------------------
		std::vector- initialization and assignment

		std::vector<int> vec {1,2,3,4,5};
		std::vector<int> vec1(10,100); // ten 100s

		std::vector<std::string>stooges{
			"larry","Moe","Curly"
		};
		vec1 = {2,4,6,7,8,10};
-----------------------------------------------------------------------------------
		std::vector- initialization and assignment

	std::vector<int> vec {1,2,3,4,5};

	std::cout << vec.size(); //5
	std::cout << vec.capacity(); //5
	std::cout << vec.max_size(); //an gigantic number

	std::cout << vec.at(0); //1
	std::cout << vec[1]; //2

	std::cout << vec.front(); //1
	std::cout << vec.back(); //5
-----------------------------------------------------------------------------------
		std::vector- initialization and assignment

	Let's say we have a class Person

	Person p1{"Larry",18};
	std::vector<Person> vec;

	vec.push_back(p1); //add p1 to the back
	vec.pop_back();  //remove p1 from the back

	vec.push_back(Person{"Larry",18});

	vec.emplace_back("Larry",18);  //Efficient
-----------------------------------------------------------------------------------
		std::vector common methods

	std::vector<int> vec1 {1,2,3,4,5};
	std::vector<int> vec2 {10,20,30,40,50};

	std::cout << vec1.empty(); // 0 false
	ve1.swap(vec2); swaps the 2 vectors

	std::sort(vec1.begin(),vec1.end()); //sorting
-----------------------------------------------------------------------------------
		std::vector common methods

	std::vector<int> vec1 {1,2,3,4,5};
	std::vector<int> vec2 {10,20,30,40,50};

	auto it = std::find(vec1.begin(),vec1.end(),3);
	vec1.insert(it,10); // 1,2,10,3,4,5

	it = std::find(vec1.begin(),vec1.end(),4);
	vec1.insert(it,vec2.begin(),vec2.end());
	//1,2,10,3,10,20,30,40,50,4,5
-----------------------------------------------------------------------------------





*/
class Person {
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name, int age) :name{ name }, age{ age }{}
	bool operator<(const Person& rhs)const {
		return this->age < rhs.age;
	}
	bool operator==(const Person& rhs)const {
		return this->name == rhs.name && this->age == rhs.age;
	}
	friend std::ostream& operator<<(std::ostream& os, const Person& rhs) {
		os << rhs.name << ": " << rhs.age;
		return os;
	}
};
template <typename T1>
void display(std::vector<T1>& vec) {
	for (auto const& i : vec) {
		std::cout << i << "  ";
	}
	std::cout << std::endl;
}

int main() {
	
	

	


}



	
