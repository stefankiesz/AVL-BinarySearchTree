#include"Tree.h"

Tree::Tree()
{
	myRoot = nullptr;
}

bool Tree::inserter(Node* root, string name, int id)
{
	if (root == nullptr)
	{
		myRoot = new Node(name, id);
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
		if ((ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) && ascii != 32)
		{
			cout << "unsuccessful" << endl;
			return false;
		}
	}
	// TODO: allow for values smaller than 10000000, parse the zeros away, add them back when printing
	if (id < 10000000 || id > 99999999)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	if (inserter(myRoot, name, id))
	{
		cout << "successful" << endl;
		return true;
	}
	cout << "unsuccessful" << endl;
	return false;
}
// change
// This is more of a search method
// it searches for the id's parent node;
// root should be the search tree's root
// returns nullptr if not found or if the node is the tree's root
Node* Tree::traversal(Node* root, int id)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->myId == id)
	{
		return nullptr;
	}
	if (root->myId > id)
	{
		if (root->left == nullptr)
		{
			return nullptr;
		}
		if (root->left->myId == id)
		{
			return root;
		}
		return traversal(root->left, id);
	}
	else
	{
		if (root->right == nullptr)
		{
			return nullptr;
		}
		if (root->right->myId == id)
		{
			return root;
		}
		return traversal(root->right, id);
	}
}

bool Tree::remove(int id)
{
	// Case for when the node to remove is the root of tree
	// (traversal() does not work for root nodes)
	if (myRoot->myId == id)
	{
		if (myRoot->left == nullptr && myRoot->right == nullptr)
		{
			delete myRoot;
			myRoot = nullptr;
			cout << "successful" << endl;
			return true;
		}
		else if (myRoot->left != nullptr && myRoot->right == nullptr)
		{
			Node* temp = myRoot;
			myRoot = myRoot->left;
			delete temp;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, right child node from the node to remove
		else if (myRoot->right != nullptr && myRoot->left == nullptr)
		{
			Node* temp = myRoot;
			myRoot = myRoot->right;
			delete temp;
			cout << "successful" << endl;
			return true;
		}
		// If there are two nodes from the node to remove
		else
		{
			// This is the parent of the node that will replace the removed node
			Node* bruhParent = myRoot->right;

			// Case of no left node from node directly to the right of Node to be removed
			if (bruhParent->left == nullptr)
			{
				bruhParent->left = myRoot->left;
				delete myRoot;
				myRoot = bruhParent;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
			// TODO: Note: the below line is also different between two large-scope cases (remove node being to the left/right of parent)
			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}
			bruhParent->left->left = myRoot->left;
			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myId;
				temp->left = bruhParent->left->right->left;
				temp->right = bruhParent->left->right->right;
				delete bruhParent->left->right;
				bruhParent->left->right = myRoot->right;
				delete myRoot;
				myRoot = bruhParent->left;
				bruhParent->left = temp;
			}
			else
			{
				bruhParent->left->right = myRoot->right;
				delete myRoot;
				myRoot = bruhParent->left;
				bruhParent->left = nullptr;

			}
			cout << "successful" << endl;
			return true;
		}

	}

	Node* parent = traversal(myRoot, id);
	if (parent == nullptr)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	Node* removeNode = nullptr;

	// If node to remove is to the left of the identified parent
	if (parent->left != nullptr && parent->left->myId == id)
	{
		removeNode = parent->left;
		// If there are not child nodes from the node to remove
		if (removeNode->left == nullptr && removeNode->right == nullptr)
		{
			parent->left = nullptr;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, left child node from the node to remove
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			parent->left = removeNode->left;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, right child node from the node to remove
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			parent->left = removeNode->right;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// If there are two nodes from the node to remove
		else
		{
			// This is the parent of the node that will replace the removed node
			Node* bruhParent = removeNode->right;

			// Case of no left node from node directly to the right of Node to be removed
			if (bruhParent->left == nullptr)
			{
				bruhParent->left = removeNode->left;
				parent->left = bruhParent;
				delete removeNode;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
			// TODO: the below line is also different between two large-scope cases (remove node being to the left/right of parent)
			parent->left = bruhParent->left;
			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}
			bruhParent->left->left = removeNode->left;
			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myId;
				temp->left = bruhParent->left->right->left;
				temp->right = bruhParent->left->right->right;
				delete bruhParent->left->right;
				bruhParent->left->right = removeNode->right;
				bruhParent->left = temp;
			}
			else
			{
				bruhParent->left->right = removeNode->right;
				bruhParent->left = nullptr;
			}
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// TODO: can prob just have one return true at the end here
		// (the false returns should all be handled at the start)
	}
	// If node to remove is to the right of the identified parent
	else
	{
		removeNode = parent->right;
		if (removeNode->left == nullptr && removeNode->right == nullptr)
		{
			parent->right = nullptr;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			parent->right = removeNode->left;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			parent->right = removeNode->right;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}

		// If there are two nodes from the node to remove
		else
		{
			// This is the parent of the node that will replace the removed node
			Node* bruhParent = removeNode->right;

			// Case of no left node from node directly to the right of Node to be removed
			if (bruhParent->left == nullptr)
			{
				bruhParent->left = removeNode->left;
				// TODO: clean this up, the only difference between the 2 child case of left/right remove node
				// of parent is the below line - reuse all the other code
				parent->right = bruhParent;
				delete removeNode;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
			parent->right = bruhParent->left;
			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}
			bruhParent->left->left = removeNode->left;
			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myId;
				temp->left = bruhParent->left->right->left;
				temp->right = bruhParent->left->right->right;
				delete bruhParent->left->right;
				bruhParent->left->right = removeNode->right;
				bruhParent->left = temp;
			}
			else
			{
				bruhParent->left->right = removeNode->right;
				bruhParent->left = nullptr;
			}
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// TODO: can prob just have one return true at the end here
		// (the false returns should all be handled at the start)
	}

}

bool Tree::search(int id)
{
	if (myRoot->myId == id)
	{
		cout << myRoot->myName << endl;
		return true;
	}
	Node* parent = traversal(myRoot, id);
	if (parent == nullptr)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	if (parent->left != nullptr && parent->left->myId == id)
	{
		cout << parent->left->myName << endl;
		return true;
	}
	else
	{
		cout << parent->right->myName << endl;
		return true;
	}
}


void Tree::inorderHelper(Node* root)
{
	if (root != nullptr)
	{
		inorderHelper(root->left);
		cout << root->myName << ", ";
		inorderHelper(root->right);
	}
}

void Tree::preorderHelper(Node* root)
{
	if (root != nullptr)
	{
		cout << root->myName << ", ";
		preorderHelper(root->left);
		preorderHelper(root->right);
	}
}

void Tree::printInorder()
{
	inorderHelper(myRoot);
	cout << endl;
}

 void Tree::printPreorder()
{
	 preorderHelper(myRoot);
	 cout << endl;
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