#include"Tree.h"

using namespace std;

int main()
{
	Tree treeInstance;

	int commandCount;
	cin >> commandCount;

	for (int i = 0; i < commandCount; i++)
	{
		string inputString;
		cin >> inputString;

		// INSERT
		if (inputString.substr(0, 6).compare("insert") == 0)
		{
			// Validate that a space and double quote surround the name
			if (inputString.substr(6, 2).compare(" \"") != 0 ||
				inputString.substr(inputString.length() - 10, 2).compare("\" ") != 0)
			{
				cout << "unsuccessful" << endl;
				continue;
			}

			string nodeName = inputString.substr(8, inputString.length() - 18);
			string nodeId = inputString.substr(inputString.length() - 8);
		}
	}



	/*
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
	*/
}