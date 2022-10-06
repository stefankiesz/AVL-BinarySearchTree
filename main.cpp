#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	myTree.insert("five", 5);
	myTree.insert("three", 3);
	myTree.insert("eight", 8);
	myTree.insert("ten", 10);


	// myTree.printInorder();
	// myTree.printPostorder();
	// myTree.printPreorder();
	// myTree.printLevelCount();

	cout << myTree.myRoot->myHeight << endl;
	cout << myTree.myRoot->myName << endl;

	cout << myTree.myRoot->left->myHeight << endl;
	cout << myTree.myRoot->left->myName << endl;

	cout << myTree.myRoot->right->myHeight << endl;
	cout << myTree.myRoot->right->myName << endl;

	cout << myTree.myRoot->right->left->myHeight << endl;
	cout << myTree.myRoot->right->left->myName << endl;

	cout << myTree.myRoot->right->left->left->myHeight << endl;
	cout << myTree.myRoot->right->left->left->myName << endl;

	cout << myTree.myRoot->right->left->right->myHeight << endl;
	cout << myTree.myRoot->right->left->right->myName << endl;

	cout << myTree.myRoot->right->left->left->right->myHeight << endl;
	cout << myTree.myRoot->right->left->left->right->myName << endl;

	cout << myTree.myRoot->right->left->right->right->myHeight << endl;
	cout << myTree.myRoot->right->left->right->right->myName << endl;


	myTree.remove(3);


	cout << myTree.myRoot->myHeight << endl;
	cout << myTree.myRoot->myName << endl;

	cout << myTree.myRoot->left->myHeight << endl;
	cout << myTree.myRoot->left->myName << endl;

	cout << myTree.myRoot->right->myHeight << endl;
	cout << myTree.myRoot->right->myName << endl;

	cout << myTree.myRoot->right->left->myHeight << endl;
	cout << myTree.myRoot->right->left->myName << endl;

	cout << myTree.myRoot->right->left->left->myHeight << endl;
	cout << myTree.myRoot->right->left->left->myName << endl;


	cout << myTree.myRoot->right->left->right->myHeight << endl;
	cout << myTree.myRoot->right->left->right->myName << endl;

	cout << myTree.myRoot->right->left->right->right->myHeight << endl;
	cout << myTree.myRoot->right->left->right->right->myName << endl;



	cout << "printLevelCount() output: ";
	myTree.printLevelCount();

	return 0;
}