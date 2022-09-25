#pragma once
#include"Node.h"
class Tree
{
public:
	Node* root;

	Tree();

	bool inserter(Node* root, string name, int id);
	bool insert(string name, int id);
	void remove(int id);
	void search(int id);
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelCount();
	void removeInorder(int n);

	void balanceTree();

};

