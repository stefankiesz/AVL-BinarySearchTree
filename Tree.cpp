#include"Tree.h"

Tree::Tree()
{
	root = nullptr;
}

bool Tree::inserter(Node* root, string name, int id)
{
	if (root == nullptr)
	{
		this->root = new Node(name, id);
		return true;
	}
	if (root->myId == id)
	{
		return false;
	}
	if (root->myId > id)
	{
		if (root->left == nullptr)
		{
			root->left = new Node(name, id);
			return true;
		}
		return inserter(root->left, name, id);
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = new Node(name, id);
			return true;
		}
		return inserter(root->right, name, id);
	}
}

bool Tree::insert(string name, int id)
{
	return inserter(this->root, name, id);
}


void Tree::remove(int id)
{

}
void Tree::search(int id)
{

}

void Tree::printInorder()
{

}
void Tree::printPreorder()
{

}
void Tree::printPostorder()
{

}
void Tree::printLevelCount()
{

}
void Tree::removeInorder(int n)
{

}

void balanceTree()
{

}