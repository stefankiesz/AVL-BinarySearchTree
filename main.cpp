#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	myTree.insert("five", 5);
	myTree.insert("three", 3);
	myTree.insert("eight", 8);
	myTree.insert("ten", 10);


	myTree.printInorder();
	myTree.printHeightsInorder();


	myTree.remove(8);


	myTree.printInorder();
	myTree.printHeightsInorder();


	cout << "printLevelCount() output: ";
	myTree.printLevelCount();

	return 0;
}