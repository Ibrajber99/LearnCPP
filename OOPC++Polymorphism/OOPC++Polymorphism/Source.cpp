#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <istream>
#include <ostream>

/*
                    //Polymorphism and inheritance
Section overview

what is polymorphism
Using base class pointers
static vs Dynamic binding
virtual functions
virtual destructors
The override and final specifiers
Using base class references
Pure virtual function and abstract classes
Abstract class as interfaces
-----------------------------------------------------
						//What is polymorphism
Fundamental to object-oriented Programming

Polymorphism:
	Compile time/early-binding/static binding
	Run-Time/lat binding / dynamic binding

Runtime poly
	being able to assing different meanings to the same functions at run time

Allows us to program more abstractly
	think general vs specific
	Let c++ figure out which function to call at run-Time

Not the default in C++, run time polymorphism is achieved via
	Inheritance
	Base class pointers or references
	Virtual functions


-----------------------------------------------------
An NON-polymorphic example - static binding

Account a;
a.withdraw(1000); //Account::wiithdraw()

b.withdraw(1000);  //Account::withdraw()
									 
Checking c;							  
c.withdraw(1000) //Account::withdraw()
									  
Trust d;							  
d.withdraw(1000) // Trust::withdraw()

Account *p = new Trust();
p->withdraw(1000);   //Account::withdraw()
					//Should be Trust::withdraw()


class Base {
public:
	 void sayHello() {
		std::cout << "Hello - Im a base class object\n";
	}
};

class Derived : public Base {
public:
	void sayHello() {
		std::cout << "Hello - I'm Derived class Object\n";
	}
};

void greeting(Base& obj) {
	std::cout << "Greetings!: ";
	obj.sayHello();
}


int main() {
	Base b;
	b.sayHello();

	Derived d;
	d.sayHello();

	greeting(d); //Can be called since derived is a child of Base
	greeting(b);


	Base* ptr = new Derived();
	ptr->sayHello(); //it supposed to retuirn hello from derived but we are not using virtual functions
	delete ptr; //Release memeory always
}

-----------------------------------------------------
A polymorphic example - Dynamic Binding

Account a;
a.withdraw(1000); //Account::wiithdraw()

b.withdraw(1000);  //Account::withdraw()

Checking c;
c.withdraw(1000) //Account::withdraw()

Trust d;
d.withdraw(1000) // Trust::withdraw()

Account *p = new Trust();
p->withdraw(1000);  // Trust::withdraw()

This possible since withdraw method is Virtual in Account class
-----------------------------------------------------

Using Baseclass Pointer

For dynamic polymorphism we must have:

Inheritance
Base class pointer or base lcass reference
Virtual functions
-----------------------------------------------------

Virtual functions

Redefined functions are bound statically
Overridden functions are bound dynamically
Virtual functions are overridden
Allow us to treat all objects generally as objects of the base class

Declaring virtual functions

Declare the function you want to override as virtual in the base class
Virtual functions are virtual all the way down the hierarchy from this point
Dynamic polymorphism only via account class pointer or reference

class Account {
public:

Virtual void withdraw (double amount);
}
Delcaring virtual functions (cont'd)

Override the function in the derived classes
Function signature and return type must match exactly
virtual Keyword not required but is best practice
if you don't provide an overriden version it is inherited from it's base class

class Checking : public Account {
public:
virtual void withdraw(double amount);
}
-----------------------------------------------------
Virtual destructors

Problems can happen when we destroy polymorphic objects

if a derivedclass is destroyed by deleting its storage viaa the base class pointer
and the class a non virtual destructor.then the behavior is undefined in the C++ standard

Derived objects must be destroyed in the correct order starting at the correct destructor

Virtual destructors
Solution/Rules
	if a class has virtual functions
	Always provide a public virtual destructor
	if base class destructor is virtual then all derived class destructors are also virtual

	class Account{
	public:
	virtual void withdraw(double amount);
	virtual ~Account();

	};
-----------------------------------------------------
The Override Specifier

We can override Base class virtual functions
The function singature and return must be EXACTLY the same
if they are different then we have redefinition NOT overriding
Redefinition is statically bound
Overriding is dynamically bound
C++11 prrovides an override specifier to have the compiler ensure overriding
-----------------------------------------------------
             The final specifier

C++11 provides the final specifier
	When used at the class level
	prevent a class from being derived

When used at the method level
Prevents virtual method from being overriden in derived classes

final Class

class MyClass final
{

};

class Derived final: public base
{
};
-----------------------------------------------------
                    Using Base class references

We can also use base class references with dynamic Polymorphism
Useful when we pass objects to functions thatexpect a base class reference

void do_withdraw(Account &account, double amount){

	account.wothdraw(amount);
}
Account a;
Account &ref = a;

ref.withdraw(1000); //Account::withdraw

Trust t;
Account &ref = t;
ref1.withdraw(10); //Trust::withdraw

//Code below is a demonstration for most of the subjects that are discussed above
class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Account::withdraw\n";
	}
	virtual ~Account() { std::cout << "Account::Destructor\n"; }
	void doWithdraw(Account& account, double amount) {

		account.withdraw(amount);//it is gonna be called dynamic binding
	}
};
class Checking : public Account {
public:
	~Checking() {
		std::cout << "Checking::Destructor\n";
	}
	virtual void withdraw(double amount) override {
		std::cout << "In checking::withdraw\n";
	}
};
class Savings : public Account {
public:
	~Savings() {
		std::cout << "Savings::Destructor\n";
	}
	virtual void withdraw(double amount) override {
		std::cout << "In Savings::withdraw\n";
	}
};
class Trust : public Account {
public:
	~Trust() {
		std::cout << "Trust::Destructor\n";
	}
	virtual void withdraw(double amount)override {
		std::cout << "In Trust::withdraw\n";
	}
};



int main() {

	Account* p1 = new Account();
	Account* p2 = new Checking();
	Account* p3 = new Savings();
	Account* p4 = new Trust();
	Account* array[] = { p1,p2,p3,p4 };
	for (int i{ 0 }; i < 4; i++) {

		array[i]->doWithdraw((*array[i]),1000);
	}

	delete p1;
	delete p2;
			  //Never forget to release memory
	delete p3;
	delete p4;
}
========================================================
         Pure virtual functions and abstract classes

Abstract class
	Cannot instantiate objects
	These classes are used as base classes in inheritance hierarchies
	Often referred to as Abstract Base classes

Concrete class
	Used to instantiate objects from
	All their member functions arte defined
		Checking,Account,savings Account etc....

Abstract base class
	Too generic to create objects from
		Shape,Employee,Account,Player
	Serves as parent to derived classes that may have objects
	Contains at least one pure virtual function

Pure virtual function
	Used to make a class abstract
	Specified with "=0" in it's declaration
	virtual void function() = 0; //Pure virtual function
    Typically do not provide implementation
	
	Derived classes must override the base class

	if the derived class does not override then the derivedclass isalso abstract

	Used when it doesn't make snese for a base class to have implementation
		but concrete classes must implement it

		virtual void draw() = 0 //Shape related
		virtual void cdefend() = 0 //Player

class Shape {        //Abstract
private:
   //attributes common to all shapes

public:
	virtual void draw() = 0;    //Pure virtual function
	virtual void rotate() = 0; //Pure virtual function
	virtual ~Shape();
};

class Circle: public Shape { //Concrete
private:
  //Attributes for a circle

public:
	
	virtual void draw() override{
	    //code to draw a circle
	}
	virtual void rotate() override {
	   //code to rotate a circle
	}
	virtual ~Circle();
};

Abstract Classes

Cannot be instantiated

Shape shape;               //Error
Shape *ptr = new Shape(); //Error

We can use Pointers and references to dynamically refere to concrete classes derived from them

Shape *ptr = new Circle();
ptr->draw();
ptr->rotate();
========================================================
What is using a class as an interface?

An abstract class that has only pure functions
These functions provide a general set ofr services to the user of the class
Provided as public
Each subclass is free to implement these services as needed
Every service(method) must be implemented
The service type information is strickly enforced

C++ does not provide true interfaces

We use abstract classes and pure virtual functions to achieve it

Suppose we want to be able to provide Printable support for any object we wish without knowing it's implementation at compile time


*/

class I_Print { //Interface class
	friend std::ostream& operator<<(std::ostream& os, I_Print& obj);
public:
	virtual void print(std::ostream& os) = 0;

};
std::ostream& operator<<(std::ostream& os, I_Print& obj) {
	obj.print(os);
	return os;
}

class Shape: public I_Print { //Abstract class
private:
public:

	virtual void draw() = 0; //Pure virtual function
	virtual void rotate() = 0; //Pure virtual function
	virtual ~Shape() {
		std::cout << "Destroying Base Shape class" << std::endl;
	};
	virtual void print(std::ostream& os) override {
		std::cout << "Shape\n";
	}
};
class OpenShape :public Shape { //Abstract class
public:
	virtual ~OpenShape() {};

};
class ClosedShape :public Shape { //Abstract class
public:
	virtual ~ClosedShape() {};

};
class Circle : public ClosedShape {//Concrete Class
public:
	virtual void draw() override {
		std::cout << "Drawing a circle" << std::endl;
	}
	virtual void rotate() override {
		std::cout << "Rotating a circle" << std::endl;
	}
	virtual ~Circle() {

		std::cout << "Destroying concrete Circle class" << std::endl;
	}
	virtual void print(std::ostream& os) override {
		os << "Im a Circle\n";
	}

};

class Square : public ClosedShape {//Concrete Class
public:
	virtual void draw() override {
		std::cout << "Drawing a Square" << std::endl;
	}
	virtual void rotate() override {
		std::cout << "Rotating a Square" << std::endl;
	}
	virtual ~Square() {

		std::cout << "Destroying concrete Square class" << std::endl;
	}
	virtual void print(std::ostream& os) override {
		os << "Im a Square\n";
	}

};

void ScreenRefresh(const std::vector<Shape*>& shapes) {
	for (const auto p : shapes) {
		p->draw();
		p->rotate();
	}
}


int main() {
	//Shape* ptr = new Circle();
	//Shape* ptr2 = new Square();
	//std::vector <Shape*> shapes{ ptr,ptr2 };
	//ScreenRefresh(shapes);

	//ptr->draw();
	//ptr->rotate();
	//ptr2->draw();
	//ptr2->rotate();

	//delete [] ptr;
	//delete[] ptr2;
	Shape* p = new Circle();
	std::cout << *p << std::endl;

}



























































