#include"Tree.h"

Tree::Tree()
{
	root = nullptr;
}

bool Tree::insert(Node* root, string name, int id)
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
		return insert(root->left, name, id);
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = new Node(name, id);
			return true;
		}
		return insert(root->right, name, id);
	}
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