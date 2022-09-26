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
		cout << "ID already in system!" << endl;
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
	if (inserter(myRoot, name, id))
	{
		cout << "successful" << endl;
		return true;
	}
	cout << "unsuccessful" << endl;
	return false;
}

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
	// TODO: add special case for when the node to remove is the root of tree
	// (traversal does not work for root nodes)
	
	Node* parent = traversal(myRoot, id);
	if (parent == nullptr) { return false; }
	Node* removeNode = nullptr;

	// If node to remove is to the left of the identified parent
	if (parent->left->myId == id)
	{
		removeNode = parent->left;
		// If there are not child nodes from the node to remove
		if (removeNode->left == nullptr && removeNode->right == nullptr)
		{
			parent->left = nullptr;
			delete removeNode;
			return true;
		}
		// If there is only one, left child node from the node to remove
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			parent->left = removeNode->left;
			delete removeNode;
			return true;
		}
		// If there is only one, right child node from the node to remove
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			parent->left = removeNode->right;
			delete removeNode;
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
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
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
			return true;
		}
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			parent->right = removeNode->left;
			delete removeNode;
			return true;
		}
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			parent->right = removeNode->right;
			delete removeNode;
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
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
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
			return true;
		}
		// TODO: can prob just have one return true at the end here
		// (the false returns should all be handled at the start)
	}

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