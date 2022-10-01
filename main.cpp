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
	myTree.printLevelCount();

	myTree.removeInorder(2);

	myTree.printInorder();
	myTree.printLevelCount();

	return 0;
}