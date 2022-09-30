#pragma once
#include"Node.h"
class Tree
{
public:
	Node* myRoot;

	Tree();

	bool inserter(Node* root, string name, int id);
	bool insert(string name, int id);

	Node* traversal(Node* root, int id);

	bool remove(int id);
	bool search(int id);
	void inorderHelper(Node* root);
	void preorderHelper(Node* root);
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelCount();
	void removeInorder(int n);

	void balanceTree();

};

