#pragma once
#include"Node.h"
class Tree
{
public:
	Tree();

	void insert(string name, int id);
	void remove(int id);
	void search(int id);
	void search(int id);
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelCount();
	

};

