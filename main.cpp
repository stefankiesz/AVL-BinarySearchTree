#include"Tree.h"

using namespace std;

int main()
{
	Tree myTree;
	myTree.insert("five", 5);
	myTree.insert("one", 1);
	myTree.insert("ten", 10);
	myTree.insert("seven", 7);
	myTree.insert("six", 6);
	myTree.insert("fifteen", 15);
	myTree.insert("twerlve", 12);
	myTree.insert("eleven", 11);
	myTree.insert("sixteen", 16);
	myTree.insert("seventeen", 17);
	myTree.insert("eighteen", 18);


	myTree.printInorder();
	myTree.printHeightsInorder();

	myTree.remove(10);

	myTree.printInorder();
	myTree.printHeightsInorder();


	cout << "printLevelCount() output: ";
	myTree.printLevelCount();

	return 0;
}