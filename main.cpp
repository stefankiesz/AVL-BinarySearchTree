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

	myTree.printPreorder();


	cout << "now to delete" << endl;
	myTree.remove(69569915);

	myTree.printPreorder();




	return 0;
}