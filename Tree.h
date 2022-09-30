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
	bool searchHelper(Node* root, string name, bool found);
	bool search(string name);
	void inorderHelper(Node* root);
	void preorderHelper(Node* root);
	void postorderHelper(Node* root);
	void printInorder();
	void printPreorder();
	void printPostorder();
	int levelHelper(Node* root, int level);
	void printLevelCount();
	void removeInorder(int n);

	void balanceTree();

};

