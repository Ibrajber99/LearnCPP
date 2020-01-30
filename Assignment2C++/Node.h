

#pragma once
#include <memory>
#include <iostream>
struct Node
{
	//One Arg constructor for Node
	Node(int e) :data(e), next{nullptr} {
	
	
	}
	//No Arg constructo
	Node() {
		
	}
	//Destructor
	~Node() {
		
	}
	

	int data;
	std::shared_ptr<Node> next;

};