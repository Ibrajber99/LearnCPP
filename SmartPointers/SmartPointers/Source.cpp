#include <cstdlib>
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


/*
												  Smart Pointers
											   ---Section Overview---


Issue with raw pointers
What are smart pointers?
Concept of ownership and RAII

C++ Smart Pointers
Unique pointers(unique_ptr)
shared pointers(shared_ptr)

Custome Deleters
----------------------------------------------------------------------
				Issues with Raw pointers
C++ provides absolute flexibilty with memory management
	Allocation
	Deallocation
	Lifetime Management
Some potentially srious problems
	Unintialized (wild) pointers
	Memory leaks
	Dangling pointers
	Not exception safe
OwnerShip?
Who owns the pointer?
When should a pointer be declared?
----------------------------------------------------------------------
				What are smart pointers?
Objects

can only point to heap allocated memory

Automatically call delete when no longer needed

Adhere to RAII principles

C++ Smart pointers
	Unique pointers(unique_ptr)
	shared pointers(shared_ptr)
	Weak pointer(weak_ptr)
	Auto pointers(auto_ptr) //Deprecated-we will not discuss

#include <memory>

defined by class templates
	Wrapper around a raw pointer

	overloaded operators
		Derefrence(*)
		Member selection (->)
		Pointer aithmetic not supported(++.-- etc...)

	can have custom deleters

	A simple example

	{
	std::smart_pointer<SOME_CLASS>ptr = ....
	ptr->method();
	cout << (*ptr) << endl;

	}
	//ptr will be destroyed automaticallly when no longer needed

RAII - Resource Acquisition Is Intialization

	Common idiom or pattern used in software design based on container object lifetime
	RAII objects are allocated on the stack

	Resource Acquistion
		Open file
		Allocate memory
		Acquire a lock

	Is Intialization
		The resource is acquired in a constructor

	Resource relinquishing
		Happens in the destructor
			close the file
			Deallocate the memory
			Release the lock
----------------------------------------------------------------------
						unique_ptr
Simple smart pointer-very efficent

unique_ptr
	Points to an object of type T on the heap
	it is unique-there can only be one unique_ptr<T> pointing to the object on the heap
	Owns what it points to
	cannot be assigned or copied
	CAN be moved
	When the pointer is destroyed, what it points to is automatically destroyed

unique_ptr - Creating,intializing and using

std::unique_ptr<int> p1{new int {100}};
std::Cout << *p << std::endl //100

*p1 = 200;

std::cout << *p1 << std::Endl; //200
----------------------------------------------------------------------


//Automatically deleted

unique_ptr - some other useful methods

     std::unique_ptr<int> p1{new int {100}};
     
     std::Cout << p1.get() << std::endl //Grabs the address
	 p1.reset();    //p1 is now a null ptr

	 if(p1)
		std::cout << *p1;   //wont execute ---> nullptr

		//automatically deleted
 ----------------------------------------------------------------------
 unique_ptr - user defined classes
	std::unique_ptr<Account> p1 {new Account {"Larry"}}
	std::cout << *p1 << std::endl;   //Display account

	p->deposit(1000);
	p1->withdraw(500);

	//automcatically deleted
 ----------------------------------------------------------------------
  unique_ptr - vectors and move

  std::vector<std::unique<int>> vec;

  std::uinque_ptr<int> ptr{new int {100}};

  vec.push_back(ptr);   //Error - copy not allowed

  vec.push_back(std::move(ptr));

  //automatically deleted
 ----------------------------------------------------------------------
   unique_ptr - make_unique(c++14) -> more efficent - no calls to new or delete

   std::unique_ptr<int> p = std::make_unique<int>(100);

   std::unique_ptr<int> p1 = std::make_unique<int>(300);

   auto p3 = make_unique<Player>("Hero",100,100);

   //automatically deleted
 ----------------------------------------------------------------------
 shared_ptr

 Provides shared ownership of heap objects

 shared_ptr	
	Points to an object of type T on the heap
	it is not unique-there can many shared_ptr pointing to the same object on the heap
	Establishes shared ownership relationship
	CAN be assigned and copied
	Doesn't support managing arrays by default
	When the usse count is zero, the managed object on the heap is destroyed
 ----------------------------------------------------------------------
 shared_ptr - Creatin,intializing and using

		std::shared_ptr<Test> t3{new Test (1000)};

		std::cout << *t3; // 1000

		t3 = 200;

		std::cout << *t3; // 200

		automatically deleted
 ----------------------------------------------------------------------
 shared_ptr - some other useful methods

 //use_count -> the number of shared_ptr objects managging the heap object
{
	shred_ptr<int> p1 {new int {100}};
	std::cout << p1.use_count();   // 1

	std::shared_ptr<int> p2 {p1}; // shared ownership
	std::cout << p1.use_count(); // 2

	p1.reset();  //decrement the use_count; p1 is nulled out

	std::cout << p1.use_count(); //0-
	std::cout << p2.use_count(); //1

	//automatically deleted
}
 ----------------------------------------------------------------------
 shared_ptr - vectors and move

		std::vector<std::shared_ptr<int>> vec;
		std::shared_ptr<int>ptr {new int{100}};
		vec.push_back(ptr); //OK-copy IS allowed

		std::cout << ptr.use_count(); // 2

 //autmatically deleted
 ----------------------------------------------------------------------
  shared_ptr make shared(C++11)
  {
	std::shared_ptr<int> p1 = make_shared<int>(100); //use_count : 1
	std::shared_ptr p2 {p1};                        //use_count : 2
	std::shared_ptr<int>p3;
	p3 = p1;                                       //use_count : 3
	} //automatically deleted

use make_shared -> more efficient
All 3 pointers point to the SAME object on the heap
When the use_count becomes 0 the heap object is deallocated
-----------------------------------------------------------------------
code example of what have been duscussed above


class Test {
private:
	int data;
public:
	Test() :data(0) {
		std::cout << "Test constructor" << " " << data << std::endl;}

	Test(int data) : data{ data } {std::cout << "Test constructor" << " " << data << std::endl;}

	int getData(){return data;}

	~Test() { std::cout << "Destructor" << " " << data << std::endl; }
};


int main() {

	std::unique_ptr<Test> t = std::make_unique<Test>(1000);
	std::unique_ptr<Test> t1{ new Test(100) };
	std::cout << t1->getData() << std::endl;
	std::cout << t->getData() << std::endl;
	t = std::move(t1); //Moving the value of t1 to t and t1 will become a null ptr
	std::cout << t->getData() << std::endl;
	std::shared_ptr<Test> t3{new Test (1000)};
	std::shared_ptr<Test> t4 = std::make_shared<Test>(100);
	t3 = t4;
	std::cout << t3->getData();


}
 ----------------------------------------------------------------------
 weak_ptr

 provides a non-owning "weak" reference

 weak_ptr<T>
	Points to an object of type T on the heap
	Does not participate in owning relationship
	Always created from a shared_ptr
	does not prevent string reference cycle which could prevent objects from being deleted

weak_ptr - circular or cyclic reference
	A refers to B
	B refers to A
	Shared strong ownership prevents heap deallocation

	solution- make one of the pointers non-owning or "weak"
	Now heap storage is deallocated properly

	-----------------------------------------------
	|A                                 B          |
	|shared_ptr<B>----------------shared_ptr<A>   |
	|											  |
	|											  |	
	|											  |	
	 ---------------------------------------------

class B; //forward declaration

class A {
	std::shared_ptr<B> b_ptr;
public:
	void setB(std::shared_ptr<B>& b) {
		b_ptr = b;
	}
	A() { std::cout << "A Constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
};

class B {
	std::weak_ptr<A> a_ptr; //this needs to be weak to break the string circular referencve otherwise the destructor own't be called and memory leak will occur
public:
	void setA(std::shared_ptr<A>& a) {
		a_ptr = a;
	}
	B() { std::cout << "A constructor" << std::endl; }
	~B() { std::cout << "A destructor" << std::endl; }
};

int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();

	a->setB(b);
	b->setA(a);
}
 ----------------------------------------------------------------------
 Custom deleters
	sometimes when we destroy a smart pointer we need more thaan to just destroy the object on the heap
	These are special use-cases
	C++ smart pointers allow you to provide custome deleters
	Lots of way to achieve this
		Functions
		Lambdas
		others...


 Custom deleters - functions

 void my_deleter(some_class *raw pointer){
 //your custom deleter code
	
	delete raw_pointer;
 }
 shared_ptr<Some_class>ptr {new some_class{}, my_deleter};

 Custom deleters - lambda

	shared_ptr<Test>ptr (new Test {100}, [] (Test *ptr){
		std::cout << "Using custome deleter\n;
		delete ptr;
	
	});


*/


class Test {
private:
	int data;
public:
	Test() :data(0) {
		std::cout << "Test constructor" << " " << data << std::endl;
	}

	Test(int data) : data{ data } { std::cout << "Test constructor" << " " << data << std::endl; }

	int getData() { return data; }

	~Test() { std::cout << "Destructor" << " " << data << std::endl; }
};
void myDeleter(Test* ptr) {
	std::cout << "Using custom function deleter\n";
	delete ptr;
}

int main() {
	//using a function
	std::shared_ptr<Test> ptr1{ new Test(100), myDeleter };

	//using a Lambda expression
	std::shared_ptr<Test>ptr(new Test{ 20 }, [](Test* ptr) {
		std::cout << "Using custom deleter\n";
			delete ptr; });



}
