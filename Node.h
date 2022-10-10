#pragma once
#include"Node.h"
#include<string>
#include<iostream>

using namespace std;
class Node
{
public:
	string myName;
	int myId;
	int myHeight;

	Node* left;
	Node* right;

	Node() : myName(""), myId(0), myHeight(1), left(nullptr), right(nullptr) {}
	Node(string name, int id) : myName(name), myId(id), myHeight(1), left(nullptr), right(nullptr) {}
	// Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};