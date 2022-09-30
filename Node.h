#pragma once
#include"include.h"

class Node
{
public:
	string myName;
	int myId;

	Node* left;
	Node* right;

	Node() : myName(""), myId(0), left(nullptr), right(nullptr) {}
	Node(string name, int id) : myName(name), myId(id), left(nullptr), right(nullptr) {}
	// Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};