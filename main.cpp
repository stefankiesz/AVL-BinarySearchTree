#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	cout << myTree.insert("Stefan", 69569915) << endl;
	cout << myTree.insert("BOB", 11112222) << endl;
	cout << myTree.insert("JOE", 22223333) << endl;
	cout << myTree.insert("HOE", 77778888) << endl;
	cout << myTree.insert("hello", 11112223) << endl;



	//cout << mytree.root->left->myname << endl;
	//cout << mytree.root->left->myid << endl;

	//cout << mytree.root->left->right->myname << endl;
	//cout << mytree.root->left->right->myid << endl;

	//cout << mytree.root->right->myname << endl;
	//cout << mytree.root->right->myid << endl;
	return 0;
}