


#include "pch.h"
#include "OList.h"
#include <algorithm>

/*
===========================
The Big five constructors and assignment operators
===========================
*/

//Default Constructor
OList::OList()
{

}
//Destructor
OList::~OList()
{

}
//Copy constructor whcih we assign this->object to rhs
OList::OList(OList& rhs)noexcept
{
	std::shared_ptr<Node>tmp;
	tmp = rhs.first;
	this->clear();
	while (tmp) {
		this->insert(tmp->data);
		tmp = tmp->next;
	}
	
}
//Move constructor this->object = rhs and then we clear the rhs 
OList::OList(OList&& rhs) noexcept
{
	*this = rhs;
	rhs.clear();
}

//Copy assignment operator we have a tmp node assigned to rhs.first pointer,then we clear this->first and insert all data from rhs to this
OList& OList::operator=(OList& rhs)
{
	std::shared_ptr<Node>tmp;
	tmp = rhs.first;
	this->clear();
	while (tmp) {
		this->insert(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}
//Move assignment we claer this->pointer and assign this = rhs
OList& OList::operator=(OList&& rhs) noexcept
{
	if (this == &rhs) {
		return *this;
	}

	first.reset();
	first = rhs.first;
	rhs.first.reset();
	rhs._size = 0;

	return *this;
}
/*
===========================
===========================
*/





/*
===========================
Function related to the list : insert,contains,Remove,IsEmpty,size,sort,swap
===========================
*/

//Insert function-we check if the data is inside the list if not insert in the head if it is the first elemenbt else insert next
bool OList::insert(int e)
{

	if (!contains(e)) {
		auto temp{ std::make_shared<Node>(e) };
		if (first) {

			temp->next = std::move(first);
			first = std::move(temp);
			_size++;
			return true;
		}
		else {
			first = std::move(temp);
			_size++;
			return true;

		}
	}
	else {
		return false;
	}


}
//Checking if the list conatins a specified element by traversing the list and checking
bool OList::contains(int e) const
{
	auto tmp = first.get();

	while (tmp) {
		if (tmp->data == e) {
			return true;
		}
		else {
			tmp = tmp->next.get();
		}
	}
	return false;


}

//Remove function first we check if it contain the element if so we traverse the list until we reach the elemtn and then we move the pointers
bool OList::remove(int e)
{
	if (contains(e)) {
		auto tmp = first.get();
		auto curr = first->next.get();
		while (tmp) {

			if (first->data == e) {
				first = std::move(first->next);
				_size--;
				return true;
			}
			else if (curr->data == e) {
				tmp->next = std::move(curr->next);
				_size--;

				return true;
			}
			else {
				tmp = curr;
				curr = curr->next.get();
			}
		}
	}
	else {
		return false;
	}


}

//check if the list is empty based on the size
bool OList::isEmpty()
{
	if (_size == 0) {
		return true;
	}
	else {
		return false;
	}
}
//clears out the list by resetting the pointer
void OList::clear()
{
	first.reset();
	_size = 0;
}
//bubble sort algorithm to sort the list
void OList::sort()
{

	std::shared_ptr<Node>current;
	std::shared_ptr<Node>bCurrent;
	current = first;
	bCurrent = first->next;
	int count{ 0 };
	while (count < _size - 1) {
		for (int j{ 0 }; j < _size - 1; j++) {
			if (bCurrent != nullptr) {
				if (current->data > bCurrent->data) {
					swap(current, bCurrent);
				}
				current = bCurrent;
				bCurrent = bCurrent->next;
			}

		}
		count++;
		current = first;
		bCurrent = first->next;
	}

}
//Swap function that is used in the sorting function
void OList::swap(std::shared_ptr<Node> a, std::shared_ptr<Node> b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

//function that returns the size
int OList::size()
{
	return _size;
}
/*
===========================
===========================
*/





/*
===========================
output stream and Arethmatic Overloaded operators + - /
===========================
*/

//output stream that prints out the list
std::ostream& operator<<(std::ostream& os, OList& list)
{
	std::shared_ptr<Node>head;
	head = list.first;
	if (!list.isEmpty()) {
		list.sort();
		os << "{";
		while (head) {
			if (head->next == nullptr) {
				os << "[" << head->data << "]";
			}
			else {
				os << "[" << head->data << "], ";
			}

			head = head->next;

		}
		os << "}";
	}
	else {
		os << "{}";
	}
	return os;


}

//Addition overloaded operator
OList& operator+(OList& list1, OList& list2)
{

	std::shared_ptr<Node>tmp;
	tmp = list2.first;
	while (tmp) {
		if (!list1.contains(tmp->data)) {
			list1.insert(tmp->data);
			//tmp = tmp->next;
		}
		else {
			tmp = tmp->next;
		}

	}
	return list1;
}

//Subtraction overloaded operator
OList& operator-(OList& list1, OList& list2)
{
	std::shared_ptr<Node>tmp;
	tmp = list2.first;

	while (tmp) {
		if (list1.contains(tmp->data)) {
			list1.remove(tmp->data);
		}
		else {
			tmp = tmp->next;
		}

	}
	return list1;
}

//Divison overloaded operator
OList& operator/(OList& list1, OList& list2)
{

	std::shared_ptr<Node>tmp;
	std::shared_ptr<Node>tmp2;
	tmp = list1.first;
	tmp2 = list2.first;
	OList list3;

	while (tmp2) {
		if (tmp2 != nullptr) {
			if (list1.contains(tmp2->data)) {
				list3.insert(tmp2->data);

			}
		}
		tmp2 = tmp2->next;
	}
	list1 = list3;
	return list1;
}
/*
===========================
===========================
*/