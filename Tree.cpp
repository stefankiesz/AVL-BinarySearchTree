#include"Tree.h"

// TODO: make the proper things private, bruhhh
// TODO: check for any test couts, TOdo's
// TODO: make destructors

Tree::Tree()
{
	myRoot = nullptr;
}

bool Tree::inserter(Node* root, string name, int id, bool& newLevel)
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
			if (root->right == nullptr)
			{
				newLevel = true;
			}
			if (newLevel && ((root->left != nullptr && root->left->myHeight == root->myHeight) ||
				(root->right != nullptr && root->right->myHeight == root->myHeight)))
			{
				root->myHeight++;
			}
			return true;
		}
		else if (root->left->myId == id)
		{
			return false;
		}
		bool output = inserter(root->left, name, id, newLevel);
		if (newLevel && ((root->left != nullptr && root->left->myHeight == root->myHeight) ||
			(root->right != nullptr && root->right->myHeight == root->myHeight)))
		{
			root->myHeight++;
		}
		return output;
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = new Node(name, id);
			if (root->left == nullptr)
			{
				newLevel = true;
			}
			if (newLevel && ((root->left != nullptr && root->left->myHeight == root->myHeight) ||
				(root->right != nullptr && root->right->myHeight == root->myHeight)))
			{
				root->myHeight++;
			}
			return true;
		}
		else if (root->right->myId == id)
		{
			return false;
		}
		bool output = inserter(root->right, name, id, newLevel);
		if (newLevel && ((root->left != nullptr && root->left->myHeight == root->myHeight) ||
			(root->right != nullptr && root->right->myHeight == root->myHeight)))
		{
			root->myHeight++;
		}
		return output;
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
	if (id < 0 || id > 99999999)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	bool newLevel = false;
	if (inserter(myRoot, name, id, newLevel))
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
// TODO: will make it also update the Nodes' height members
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

Node* Tree::traversal(Node* root, int id, bool& decrementHeight)
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
			if (root->right == nullptr || root->right->myHeight + 1 < root->myHeight)
			{
				decrementHeight = true;
				root->myHeight--;
			}
			return root;
		}
		Node* returnNode = traversal(root->left, id, decrementHeight);
		cout << "Names::: " << root->myName << endl;
		if (decrementHeight && (root->right == nullptr || root->myHeight > root->right->myHeight + 1) &&
			(root->left == nullptr || root->myHeight > root->left->myHeight + 1))
		{
			cout << "yep" << endl;
			root->myHeight--;
		}
		return returnNode;
	}
	else
	{
		if (root->right == nullptr)
		{
			return nullptr;
		}
		if (root->right->myId == id)
		{
			if (root->left == nullptr || root->left->myHeight + 1 < root->myHeight)
			{
				decrementHeight = true;
				root->myHeight--;
			}
			return root;
		}
		Node* returnNode = traversal(root->right, id, decrementHeight);
		if (decrementHeight && (root->left == nullptr || root->myHeight > root->left->myHeight + 1) &&
			(root->right == nullptr || root->myHeight > root->right->myHeight + 1))
		{
			root->myHeight--;
		}
		return returnNode;
	}
}

bool Tree::remove(int id)
{

	// Case for when the node to remove is the root of tree
	// (traversal() does not work for root nodes)
	if (myRoot->myId == id)
	{
		// If there are no child nodes from the node to remove
		if (myRoot->left == nullptr && myRoot->right == nullptr)
		{
			delete myRoot;
			myRoot = nullptr;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, left child node from the node to remove
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
				if (myRoot->left->myHeight >= myRoot->right->myHeight)
				{
					bruhParent->myHeight = myRoot->myHeight;
				}
				bruhParent->left = myRoot->left;
				delete myRoot;
				myRoot = bruhParent;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
			// TODO: Note: the below line is also different between two large-scope cases
			// (remove node being to the left/right of parent)
			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}

			// Here we call traversal on the node to replace the removed node,
			// this is to decrement the Heights if necessary
			bool decrementHeights = false;
			traversal(myRoot, bruhParent->left->myId, decrementHeights);

			bruhParent->left->left = myRoot->left;

			// Here, the height of replacing node is set to equal the removed root's height
			// the traversal() call above already accounts for whether or not the movement of the 
			// node will influence the height
			bruhParent->left->myHeight = myRoot->myHeight;

			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myName;
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


	// bool decrementHeights = false;
	// Node* parent = traversal(myRoot, id, decrementHeights);
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
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

			parent->left = nullptr;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, left child node from the node to remove
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

			parent->left = removeNode->left;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		// If there is only one, right child node from the node to remove
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

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
				if (removeNode->left->myHeight >= removeNode->right->myHeight)
				{
					bruhParent->myHeight = removeNode->myHeight;
				}
				else
				{
					bool decrementHeights = false;
					traversal(myRoot, removeNode->myId, decrementHeights);
				}
				bruhParent->left = removeNode->left;
				parent->left = bruhParent;
				delete removeNode;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed

			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}

			// Here accounting for any height decrementing that may come from moving the node
			bool decrementHeights = false;
			traversal(myRoot, bruhParent->left->myId, decrementHeights);

			parent->left = bruhParent->left;


			bruhParent->left->myHeight = removeNode->myHeight;

			bruhParent->left->left = removeNode->left;
			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myName;
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
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

			parent->right = nullptr;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

			parent->right = removeNode->left;
			delete removeNode;
			cout << "successful" << endl;
			return true;
		}
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			bool decrementHeights = false;
			traversal(myRoot, removeNode->myId, decrementHeights);

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
				if (removeNode->left->myHeight >= removeNode->right->myHeight)
				{
					bruhParent->myHeight = removeNode->myHeight;
				}
				else
				{
					bool decrementHeights = false;
					traversal(myRoot, removeNode->myId, decrementHeights);
				}
				bruhParent->left = removeNode->left;
				// TODO: clean this up, the only difference between the 2 child case of left/right remove node
				// of parent is the below line - reuse all the other code
				parent->right = bruhParent;
				delete removeNode;
				cout << "successful" << endl;
				return true;
			}

			// Case of there are node(s) to the left of the node directly right of Node to be removed
			while (bruhParent->left->left != nullptr)
			{
				bruhParent = bruhParent->left;
			}

			// Here accounting for any height decrementing that may come from moving the node
			bool decrementHeights = false;
			traversal(myRoot, bruhParent->left->myId, decrementHeights);

			parent->right = bruhParent->left;


			bruhParent->left->myHeight = removeNode->myHeight;

			bruhParent->left->left = removeNode->left;
			if (bruhParent->left->right != nullptr)
			{
				Node* temp = new Node();
				temp->myId = bruhParent->left->right->myId;
				temp->myName = bruhParent->left->right->myName;
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
	if (myRoot == nullptr)
	{
		cout << "unsuccessful" << endl;
		return false;
	}
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

bool Tree::searchHelper(Node* root, string name, bool found)
{
	if (root != nullptr)
	{
		found = searchHelper(root->left, name, found);
		if (root->myName.compare(name) == 0)
		{
			found = true;

			int maxCheck = 10000000;
			string zerosString = "";
			while (true)
			{
				if (root->myId < maxCheck)
				{
					zerosString += "0";
				}
				else { break; }
				maxCheck /= 10;
			}
			cout << zerosString << root->myId << endl;
		}
		found = searchHelper(root->right, name, found);
	}
	return found;
}

bool Tree::search(string name)
{
	if (!searchHelper(myRoot, name, false))
	{
		cout << "unsuccessful" << endl;
		return false;
	}
	return true;
}

void Tree::inorderHelper(Node* root, string& output)
{
	if (root != nullptr)
	{
		inorderHelper(root->left, output);
		output += root->myName + ", ";
		inorderHelper(root->right, output);
	}
}

void Tree::preorderHelper(Node* root, string& output)
{
	if (root != nullptr)
	{
		output += root->myName + ", ";
		preorderHelper(root->left, output);
		preorderHelper(root->right, output);
	}
}

void Tree::postorderHelper(Node* root, string& output)
{
	if (root != nullptr)
	{
		postorderHelper(root->left, output);
		postorderHelper(root->right, output);
		output += root->myName + ", ";
	}
}

void Tree::printInorder()
{
	string output;
	inorderHelper(myRoot, output);
	cout << output.substr(0, output.length() - 2 ) << endl;
	cout << endl;
}

void Tree::printPreorder()
{
	string output;
	preorderHelper(myRoot, output);
	cout << output.substr(0, output.length() - 2) << endl;
	cout << endl;
}

void Tree::printPostorder()
{
	string output;
	postorderHelper(myRoot, output);
	cout << output.substr(0, output.length() - 2) << endl;
	cout << endl;
}

int Tree::levelHelper(Node* root, int level)
{
	if (root != nullptr)
	{
		level++;
		level = max(levelHelper(root->left, level), levelHelper(root->right, level));
	}
	return level;
}

// TODO: make sure this uses correct starting point: 0 or 1?
void Tree::printLevelCount()
{
	cout << levelHelper(myRoot, 0) << endl;
}

int Tree::removeInorderHelper(Node* root, int n)
{
	if (root != nullptr)
	{
		n = removeInorderHelper(root->left, n);
		if (n == 0)
		{
			remove(root->myId);
			return -1;
		}
		if (n < 0) { return n; }
		n--;
		n = removeInorderHelper(root->right, n);
	}
	return n;
}

void Tree::removeInorder(int n)
{
	if (removeInorderHelper(myRoot, n) >= 0){ cout << "unsuccessful" << endl; }
}

void balanceTree(Node* root)
{
	if (root != nullptr)
	{
		balanceTree(root->left);
	}
}



void Tree::heightsInorderHelper(Node* root, string& output)
{
	if (root != nullptr)
	{
		heightsInorderHelper(root->left, output);
		output += to_string(root->myHeight) + ", ";
		heightsInorderHelper(root->right, output);
	}
}


void Tree::printHeightsInorder()
{
	string output;
	heightsInorderHelper(myRoot, output);
	cout << output.substr(0, output.length() - 2) << endl;
	cout << endl;
}