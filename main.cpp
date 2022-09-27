#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	myTree.insert("Stefan", 69569915);
	myTree.insert("BOB", 22223333);
	myTree.insert("JOE", 11112222);
	myTree.insert("HOE", 77778888);
	myTree.insert("hello", 44445555);
	myTree.insert("bye", 33334444);


	cout << myTree.myRoot->myId << endl;
	cout << myTree.myRoot->left->myId << endl;
	cout << myTree.myRoot->right->myId << endl;
	cout << myTree.myRoot->left->left->myId << endl;
	cout << myTree.myRoot->left->right->myId << endl;
	if (myTree.myRoot->left->right->right != nullptr)
	{
		cout << myTree.myRoot->left->right->right->myId << endl;

	}
	if (myTree.myRoot->left->right->left != nullptr)
	{
		cout << myTree.myRoot->left->right->left->myId << endl;

	}


	cout << "now to delete" << endl;
	myTree.remove(69569915);

	cout << myTree.myRoot->myId << endl;
	cout << myTree.myRoot->left->myId << endl;
	// cout << myTree.myRoot->right->myId << endl;
	cout << myTree.myRoot->left->left->myId << endl;
	cout << myTree.myRoot->left->right->myId << endl;
	if (myTree.myRoot->left->right->right != nullptr)
	{
		cout << myTree.myRoot->left->right->right->myId << endl;

	}
	if (myTree.myRoot->left->right->left != nullptr)
	{
		cout << myTree.myRoot->left->right->left->myId << endl;

	}


	//cout << mytree.root->left->myname << endl;
	//cout << mytree.root->left->myid << endl;

	//cout << mytree.root->left->right->myname << endl;
	//cout << mytree.root->left->right->myid << endl;

	//cout << mytree.root->right->myname << endl;
	//cout << mytree.root->right->myid << endl;
	return 0;
}