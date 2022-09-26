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
		cout << "ID already in system!" << endl;
		return false;
	}
	if (root->myId > id)
	{
		cout << "id: " << id << endl;
		cout << "RootVal: " << root->myId << endl;
		if (root->left != nullptr)
		{
			cout << "LeftVal: " << root->left->myId << endl;
		}
		else
		{
			cout << "LeftVal NULL" << endl;
		}

		if (root->left == nullptr)
		{
			root->left = new Node(name, id);
			return true;
		}
		else if (root->left->myId == id)
		{
			cout << "ID already in system!" << endl;
			return false;
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
		else if (root->right->myId == id)
		{
			cout << "ID already in system!" << endl;
			return false;
		}
		return inserter(root->right, name, id);
	}
}

bool Tree::insert(string name, int id)
{
	for (int i = 0; i < name.length(); i++)
	{
		int ascii = int(name[i]);
		if (ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122)
		{
			cout << "unsuccessful" << endl;
			return false;
		}
	}
	if (id < 10000000 || id > 99999999)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	if (inserter(this->root, name, id))
	{
		cout << "successful" << endl;
		return true;
	}
	cout << "unsuccessful" << endl;
	return false;
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