#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include <cstring>
#include <ostream>
#include <istream> 

/*
//Section overview.
                   OOP Inheritance
	What is Inheritance?
		Why is it useful?
	Terminology and Notation
	Inheritance vs Composition
	Deriving classes from existing classes
		Types of inheritance
	Protected memebers and class access
	Constructors and destructors
		Passing arguments to base class constructors
		Order of constructor and destructor calls
	Redefining base class methods
	Class Hierarchies
	Multipile inheritance
-------------------------------------------------------------------
						What is inheritance?
What is it? and why is it used?

Provides a method for creating new classes from existing classes
The new class contains the data and behaviors of the existing classes
Allow for reuse of existing classes
Allows us to focus on the common attributes among a set of classes
Allow new classes to modify behaviors of existing classes to make it uniqe
	Without actually modifying the original class
	                    //Releated classes examples that using inheritance logically makes sense

Player,Enemy,Level Boss,Hero,Super player,etc...
Account,Savings account,Checking account,Trust account,etc...
Shape line,Oval,Circle,Square,etc...
Person,Employee,Student,Faculty,Staff Adminstrators,etc...
-------------------------------------------------------------------
                          //Terminolgy of Inheritance
Inheritance:
	Process of creating a new classes from existing classes
	Reuse mechanism
Single Inheritance:
	A new class is created from another "Single" class
Multiple Inheritance:
	A new class is created from two (or more) other classes

Base Class(Parent class,Super class)
	The class being extended of inherited from
Derived class(child class,sub class)
	The class being created from the base class
	Will inherit attributes and operations from base class

"Is-A" relationship
	Public inheritance
	Derived classes are sub-types of their base classes
	can use a derived class object wherever we use a base class object
Generalization
	Combining similar classes into a single,More general class based on common attributes
Specialization
	Creating new classes from existing classes proving more specialized attributes op operations
Inheritance or Class Hierarchies
	Organization of our inheritance relationship
-------------------------------------------------------------------
	                        Inheritance vs composition
							   Public inher vs comp
Both allow reuse of existing classes

Public inheritance
	-"is-a relationship"
		Employee is-a person
		Checking account is-a Account
		Circle is-a shape
Composition
 -"has-a" relationship
	Person has-a Account
	Player has-a special attack
	Circle has-a shape
-------------------------------------------------------------------
                     C++ Derivation Syntax
Class Base {
    //Base class members
}
Class Derived: access-Specifier Base{
   //Derived class members
}
Access specifier can be: Public,Private or Protected
Note: if you do not declare an access-specifie then it will private by default

Pubilc
	Most Common
	Establishes "Is-a" relationship between Derived and base Classes
Private and protected
	Establishes "Derived class has-a class" relationship
	Is implemented in terms od relationship
	Different from composition
	Example:
	Class Account {
		//Account class members
	}
	class Saving_Account: public Account{
	   //Saving_account class members
	}
	Saving_Account "is-a" Account
	Account account {};
	Account *p_account = new Account();
	account.deposit(1000.0);
	p_account->withdrawal(200.0);

	delete [] p_account;
-------------------------------------------------------------------
                           Protected Members and Class access
The protected class member modifier
 class base{
   protected:
   //protected Base class members
 }
 Accessible from the base class itself
 Accessible from classes Derived from base
 Not accessible by bjects of base or derived

 Acces with public inheritance
 -------------------------------------------------------------------

 Base Class                                          Access in Derived class
 Public: a                 <-Public inheritance->         public: a
 protected : b                                            protected : b
 private: c												  c : no access
 -------------------------------------------------------------------
 Access with portected inheritance
  Base Class                                          Access in Derived class
 Public: a                 <-Protected inheritance->      protected: a
 protected : b                                            protected : b
 private: c												  c : no access
  -------------------------------------------------------------------
Access with private inheritance

  Base Class                                          Access in Derived class
 Public: a                 <-private inheritance->      private: a
 protected : b                                          private : b
 private: c												c : no access
   -------------------------------------------------------------------

   example code of specific types of inheritance
   class Base {
public:
	int a{0};
	void display() { std::cout << a << ", " << b << ", " << c << std::endl; }
protected:
	int b{ 0 };
private:
	int c{ 0 };
};
class Derived : public Base {
	//Note friends of derived have access to noly what derived has access to
public:
	//a will be public
	//b will be protected
	//c can't access private in parent class
	void accessBaseMembers() {
		a = 100;//OK
		b = 100; //OK
		//c = 300; //Will not be accessible
	}


};
int main(){
Base base;
	base.a = 100; // OK
	//base.b = 300; //compiler error protected
	//base.c = 400; //compiler error private
	Derived  d;
	d.a = 100;
	//d.b = 200; //Error
	//d.c = 300; //Error

}
-----------------------------------------------------------------------------
                    //Constructor and destructors in Inheritance
                      Constructors and class intialization

A derived class inherits from its base
The Base part of the derived class MUST be intialized BEFORE the Derived class is intialized

When a Derived object is created
	Base class constructor executes
	then Derived class constructor executes

                          output:
Base base;                Base constructor

Derived derived;          Base constructor
                          Derived constructor
   -------------------------------------------------------------------
                       Destructors
Class destructors are invoked in the reverse order as constructors

The derived part of the derived class must be destroyed BEFORE the Base class is invoked

When a Derived object is destroyed
	Derived class destructor executes then
	Base class destructor executes
	Each destructor should free resources allocated in it's own constructors

						  output:
Base base;                Base constructor
                          Base destructor

Derived derived;          Base constructor
						  Derived constructor
						  Derived destructor
						  Base destructor
   -------------------------------------------------------------------
                         Constructors and class intialization
A derived class does NOT inherit
	Base class constructors
	Base class destructors
	Base class overloaded assignment operators
	Base class friend functions

However, the base class constructors, destructors, and overloaded assignment operators can invoke the base class versions

C++11 allows explicit inheritance of base "non-special" constructors with
	using Base::base; anywhere in the derived class declaration
	lots of rules involved, often better to define constructors yourself
   -------------------------------------------------------------------
                         Passing arguments to base class constructors
The base part of a derived class must be intialized first

how can we control exactly which base constructor is used during intialization

We can invoe the whichever Base class constructor we wish in the intialization
list of the derived class

passing arguments to base class constructors 
   -------------------------------------------------------------------
       Copy/Move constructors and overloaded operator=

Not inherited from the base class

You may not need to provide your own
	Compiler-provided versions may be just fine
We can explicitly invoke the base class versions from the derived class

copy constructor

Can invoke Base copy constructor explicitly
	Derived object "other" will be sliced

Derived::Derived(const Derived &other): Base(other),{derived initilzation list}
{};


Copy/Move constructors and overloaded operator=
Often you do not need to provide your own

if you do not define them in derived
	then the compiler will create them and automatically and cll the base class's version

if you do provide Derived versions
	then you must invoke the base version explicitly yourself

Be careful with raw pointers
	Especially if base and derived each has raw pointers
	provide them with deep copy semantics
   -------------------------------------------------------------------
                            Using and redefining Base class methods
Derived class can directly invoke Base class methods

Derived class can override or redefine Base class methods

Very powerful in the context of polymorphism

Static binding of methods calls

Binding of which method to use is done at compile time
	Default binding for C++ is static
	Derived class objects will use Derived::deposit
	But,we can explicitly invoke Base::deposit from Derived deposit
	OK,but limited-much more powerfull approach iss dynamic binding.

	see Account and SavingAccount classes for the demonstration.
   -------------------------------------------------------------------
                     Multiple Inheritance

A derived class inherits from two or more Base classes at the same time

The base classes may belong to unrelated class hierarchies

it is Easily misused and can be very complex
 
                        
*/
class Base {
private: 
	int value;
	
public:
	Base() : value(0) {
		std::cout << "Base constructor has been called\n";
	}
	Base(int x) : value{ x } {
		std::cout << "Base (int) constructor has been called\n";
	}
	Base(const Base& other) : value(other.value){}//Copy constructor
	~Base() {
		std::cout << "Base-Destructor has been called\n";
	}
	//Base& operator=(Base& rhs) {//commented out for testing purposes
	//	std::cout << "Copy constructor has been called\n";
	//	if (this == &rhs) {
	//		return *this;
	//	}
	//	value = rhs.value;
	//	return *this;
	//}
};
class Derived : public Base {
private:
	int dValue;
public:
	Derived() : dValue(0) {
		std::cout << "Base constructor has been called\n";
	}
	Derived(int x) :Base(x), dValue{ x*2 } {
		std::cout << "Base (int) constructor has been called\n";
	}
	~Derived() {
		std::cout << "Derived-Destructor has been called\n";
	}
	Derived(const Derived& other) :Base(other), dValue(other.dValue) {
	
	
	}//copy Cons wich we also invoked Base copy constructor
	Derived& operator=(Derived& rhs) {
		std::cout << "Assignment operator has been called\n";
		if (this == &rhs) {
			return *this;
		}
		Base::operator=(rhs);
		dValue = rhs.dValue;
	}
	int getV() {
		return dValue;
	}
	
};
#include "Account.h"
#include "SavingsAccount.h"
int main() {
	//Base a;
	//Base b{ 100 };
	//Derived x;
	//Derived d{ 200 };
	Derived a{ 100 };
	Derived c;
	c = a;
	std::cout << c.getV();

}