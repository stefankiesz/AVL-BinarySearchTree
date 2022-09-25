#include"Tree.h"

using namespace std;

int main()
{
	cout << "test" << endl;
	Tree myTree;
	cout << myTree.insert("Stefan", 69569915) << endl;
	cout << myTree.insert("BOB", 11112222) << endl;
	cout << myTree.insert("JOE", 22223333) << endl;
	cout << myTree.insert("HOE", 77778888) << endl;


	cout << myTree.root->left->myName << endl;
	cout << myTree.root->left->myId << endl;

	cout << myTree.root->left->right->myName << endl;
	cout << myTree.root->left->right->myId << endl;

	cout << myTree.root->right->myName << endl;
	cout << myTree.root->right->myId << endl;
	return 0;
}