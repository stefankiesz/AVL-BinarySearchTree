#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	myTree.insert("six", 69569915);
	myTree.insert("two", 22223333);
	myTree.insert("one", 11112222);
	myTree.insert("seven", 77778888);
	myTree.insert("four", 44445555);
	myTree.insert("three", 33334444);

	myTree.printInorder();
	// myTree.printPostorder();
	// myTree.printPreorder();
	// myTree.printLevelCount();

	cout << myTree.myRoot->myHeight << endl;
	cout << myTree.myRoot->myId << endl;

	cout << myTree.myRoot->left->myHeight << endl;
	cout << myTree.myRoot->left->myId << endl;

	cout << myTree.myRoot->right->myHeight << endl;
	cout << myTree.myRoot->right->myId << endl;

	cout << myTree.myRoot->left->left->myHeight << endl;
	cout << myTree.myRoot->left->left->myId << endl;

	cout << myTree.myRoot->left->right->myHeight << endl;
	cout << myTree.myRoot->left->right->myId << endl;

	cout << myTree.myRoot->left->right->left->myHeight << endl;
	cout << myTree.myRoot->left->right->left->myId << endl;


	return 0;
}