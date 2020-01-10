#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include "MyString.h"

/*
//Section overview
//Operator overloading

What is operator overloading?
Overloading the assignment operator(=)
	Copy semantics
	Move semantics
Overloading operators as member functions
Overloading operators as global functions
Overloading stream insertion (<<) and exctraction operators (>>)

				//What is operator overloading?
Using traditional operators such as +,=,* etc.. with user defined types
Allows user defined types to behave similar to built in types
Can make code more readable and writable
Not done automatically (except for the assignment operator)
they must be explicitly defined

			  //What operators can be overloaded
The majority of C++'s operators can be overloaded
The following operators cannot be overloaded->(::, :?, .*, ., sizeof)

			 //Some Basic Rules
Precedence and Associativity cannot be changed
arity cannot be changed (i.e can't make the division operator unary)
can't overload operators of primitive type(e.g int,double,etc)
can't create new operators
[], (). ->, and the assignment operator(=) must be declared as member methods
other operators can be declared as memeber methods or global functions

	----------------------------------------------------------------------------------------
	  //C++ provides a default assignment operator used for assigning one object to another

	  MyString s1 {"Frank"};
	  MyString s2 = s1; Not assginment. //Same as MyString s2{s1};
	  s2 = s1; //This assginment;
Default is memeberwise assignment(Shallow Copy)
	If we have a raw pointer data member we must deep copy

	//Example of of overloading assignment operator

	MyString &MyString::Operator=(const Mystring &rhs){

	if(this == &rhs) // p1 = p1
		return *this; //return current object

	delete [] str; //here we deallocate storage for this->str since we are overwriting it

	str = str = new char[std::strlen(rhs.str) + 1];//Allocqating storage for the deep copy
	std::strcpy(str,rhs.str); //preform a copy
	return *this; //Return the current by reference to allow chain assignment
	}
	//s1 =s2 =s3;
	----------------------------------------------------------------------------------------
					//Move Assignment operator(=)
You can choose to overload the move assignment operator
	C++ will use the copy assignment operator if necessary
	Mystring s1;
	S1 = Mystring {"Frank"}; //Move assignment
---If we have raw pointer we should overload the move assignment operator for efficiency
				 //Example of of overloading move assignment operator

				 Mystring &Mytring::operator=(Mystring &&rhs)->double && indicates that the object is an Rvalue
				 if(this == &rhs)//self assignment
				 return *this;   //return current object

				 delete str[]   //dealocate current object
				 str = rhs.str; //steal the pointer

				 rhs.str = nullptr; //null out of the rhs object
				 return *this //return current object
	----------------------------------------------------------------------------------------
			   //Unary operators as member methods (++,--,-,!):

	Number Number::operator-() const;
	Number Number::operator++();    //Pre-increment
	Number Number::operator++(int); //post increment
	bool Number::operator!() const;

	Number n1{100};
	Number n2 = - n1; //n1.operator-()
	n2 = ++n1;       // n1.operator()
	n2 = n1++       // n1.operator++(int)
				  //Example
   Mystring operator-make lowercase

   Mystring larry1 = LARRY
   Mystring larry2;
   larry1.diaply(); //LARRY
   larry2 = -larry1   //larry1.operator-()
   larry1.display(); //LARRY
   larry2.display(); larry non upper case

   code: for lowercase transform in an overloaded operator

   MyString MyString::operator-() const{
   char *buff = new char[std::strlen(str)+1];
   std::strcpy(buff,str);
   for(int i {0}; i < std::strlen(buff); i++){
		buff[i] = std::tolower(buff[i]);
   }
   MyString temp {buff};
   delete [] buff;
   return temp;

   }
	----------------------------------------------------------------------------------------
				//Binary operators as member methods (+,-,==,!=,<,>,etc...):

			Syntax->ReturnType Type::operatorOp(Const &Type rhs)

			Number Number::operator+(const &Number rhs) const;
			Number Number::operator-(const &Number rhs) const;
			bool Number::operator==(const &Number rhs) const;
			bool Number::operator<(const &Number rhs) const;

			Number n1 {100}, n2 {200};
			Number n3 = n1 + n2; //n1.operator+(n2);
			Number n3 = n1 - n2; //n1.operator-(n2);
			if (n1 == n2)... //n1.operator==(n2);
   code:
   bool Mystring::operator==(const MyString &rhs) const{
		if(std::strcmp(str,rhs.str) == 0) //std::strcmp is string comparision function from C library
			return true;
		else
			return false;
   }
	----------------------------------------------------------------------------------------
	Example:
	Mystring operator+ (concatination)

	Mystring larry{"larry"};
	Mystring more{"Moe"};

	Mystring Result = larry + moe //larry.operator+(moe);

	Code Example:
	MyString MyString::operator+(const MyString &rhs) const{

	size_t buff_size = std::strlen(str) + std::strlen(rhs.str)+ 1; //buff_size = string length of rhs.str and this->str
	char* buff = new char[buff_size]; //allocating new memeory on the heap with the same size as buff_size;
	std::strcpy(buff,str); //copy str yo buff
	std::strcat(buff,rhs.str); //concatination function
	Mystring temp {buff};//temporariy variable to hold the value
	delete [] buff;//we release buff
	return temp;//finally we return the new value which is temp

	}
	----------------------------------------------------------------------------------------
				  //Stream insertion and extraction operators(<<,>>)

	   //streeam extraction

	   MyString larry{"Larry"};
	   cout << larry << endl; //Larry

	   Player hero {"Hero", 100, 33};
	   cout << hero << endl; {name:Hero, health: 100, xp:33};

	   //stream insertion

	   MyString larry;
	   cin>>larry;

	   Player hero;
	   cin >> hero;

	 //Doesn't make sense to implement as memeber methods
		--Left operand must be a user-defined class
		--Not the way we normally use these operators

		MyString larry;
	  larry << cout    //No!!

	  Player hero;
	  hero >> cin;   //No!!
	----------------------------------------------------------------------------------------
	//Stream insertion operator(<<)

	std::ostream &operator<<(std::ostream &os, const MyString &obj){

	 os << obj.str //if friend function
	 // os << obj.get_str(); //if not friend function

	 return os;
	}
	--Return a reference to the ostream so we can keep inserting
	--Don't return ostream by value
	----------------------------------------------------------------------------------------
	//stream extraction operator (>>)

	std::istream &operator>>(std::istream &is, MyString &obj){
	char *buff =new char [1000];
	is >> buff;
	obj = MyString{buff}; //If you have copy or move assignment
	delete [] buff; //release memory
	return is;
	}
	--Return a reference to the istream so we can keep inserting
	--Updating the object passed in

*/

int main() {
	/*MyString empty;//no-args constructor
	MyString larry("larry");//Overloaded constructor
	MyString stooge{ larry };//Copy constructor
	empty.display();
	larry.display();
	stooge.display();
	empty = larry;//doing a copy assignment with the help of our assignment operator we have created
	empty = "yay";//assigning a new char data
	empty.display();//will display yay

	MyString a{ "Hello" };//Overloaded constructor
	a = MyString{ "hola" };//Overloaded constructor then move assignment
	a = "Bonjour";         //Overloaded constructor then move assignment
	a.display();
	
	MyString larry{ "LARRY" };
	MyString ome{ "Moe" };
	MyString stooge = larry;
	MyString larry2 = -larry;
	larry2.display();
	MyString stooges = -larry + " Moe";
	stooges.display();
	*/
	MyString larry{ "larry" };
	MyString moe{ "Moe" };
	MyString curly;

	std::cout << "Enter the third stooge's first name\n";
	std::cin >> curly;

	std::cout << "The three stooges are " << larry << ", " << moe << ",and " << curly << std::endl;

	std::cout << "Enter the three stooges names seperated by space: \n";
	std::cin >> larry >> moe >> curly;

	std::cout << "The three stooges are " << larry << ", " << moe << ",and " << curly << std::endl;

	return 0;
}

