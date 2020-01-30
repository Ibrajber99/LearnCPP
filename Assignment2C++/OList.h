

#pragma once
#include "Node.h"
#include <memory>
#include <list>
#include<vector>
class OList
{
	
	
public:
	OList(); //Constructor
	~OList(); //Destructor
	OList(OList& rhs)noexcept; //Copy construcotr
	OList(OList&& rhs)noexcept; //Move Constructor
	OList& operator =(OList& rhs); //Copy Assignment
	OList& operator =(OList&& rhs)noexcept;//move assignment 
	std::shared_ptr<Node>first;//shared pointer of type node that points to the start
	int _size{ 0 }; //size variable
	bool insert(int e); //Insert function
	bool contains(int e) const; //contain Node function
	bool remove(int e); //Remove Node function
	bool isEmpty(); //if list is empty function
	void clear(); //Erase the list
	void sort(); //Sort Function
	void swap(std::shared_ptr<Node>a, std::shared_ptr<Node>b); //Swap nodes function
	int size(); //size function
	std::vector<int>sortV;
	friend std::ostream& operator << (std::ostream& os, OList& list);//Output stream operator
};

//Arethmatic overloaded Operators
OList& operator+(OList& list1, OList& list2);
OList& operator-(OList& list1, OList& list2);
OList& operator/(OList& list1, OList& list2);