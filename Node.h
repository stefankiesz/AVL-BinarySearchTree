#pragma once
#include"include.h"

class Node
{
public:
	int myName;
	int myId;

	Node* left;
	Node* right;

	Node() : val(0), left(nullptr), right(nullptr) {}
	Node(int x) : val(x), left(nullptr), right(nullptr) {}
	Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

