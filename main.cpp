#include"Tree.h"

using namespace std;

int main()
{
	Tree treeInstance;

	int commandCount;
	cin >> commandCount;
	cin.ignore();

	// TODO: use ASCII to validate that all ID input are numbers


	for (int i = 0; i < commandCount; i++)
	{
		string inputString;
		getline(cin, inputString);

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
			string nodeIdString = inputString.substr(inputString.length() - 8, 8);
			int nodeIdInt;
			try
			{
				nodeIdInt = stoi(nodeIdString);
			}
			catch (const invalid_argument& e) {
				cout << "unsuccessful" << endl;
				continue;
			}

			treeInstance.insert(nodeName, nodeIdInt);
			continue;
		}

		// REMOVE
		if (inputString.substr(0, 6).compare("remove") == 0)
		{
			// Valid remove() commands have a fixed length
			if (inputString.length() != 15)
			{
				cout << "unsuccessful" << endl;
				continue;
			}

			// Validate that a space follows the command
			if (inputString.substr(6, 1).compare(" ") != 0)
			{
				cout << "unsuccessful" << endl;
				continue;
			}

			string nodeIdString = inputString.substr(7, 8);
			int nodeIdInt;
			try
			{
				nodeIdInt = stoi(nodeIdString);
			}
			catch (const invalid_argument& e) {
				cout << "unsuccessful" << endl;
				continue;
			}

			treeInstance.remove(nodeIdInt);
			continue;
		}

		// SEARCH
		if (inputString.substr(0, 6).compare("search") == 0)
		{
			// Validate that a space follows the command
			if (inputString.substr(6, 1).compare(" ") != 0)
			{
				cout << "unsuccessful" << endl;
				continue;
			}

			if (inputString.substr(7, 1).compare("\"") == 0)
			{
				// Validate input ends in a quote
				if (inputString.substr(inputString.length() - 1, 1) != "\"")
				{
					cout << "unsuccessful" << endl;
					continue;
				}
				string nodeName = inputString.substr(8, inputString.length() - 9);
				treeInstance.search(nodeName);
				continue;
			}

			// Valid search(int) commands have a fixed length
			if (inputString.length() != 15)
			{
				cout << "unsuccessful" << endl;
				continue;
			}

			string nodeIdString = inputString.substr(inputString.length() - 8, 8);
			int nodeIdInt;
			try
			{
				nodeIdInt = stoi(nodeIdString);
			}
			catch (const invalid_argument& e) {
				cout << "unsuccessful" << endl;
				continue;
			}

			treeInstance.search(nodeIdInt);
			continue;
		}

		// INVALID
		cout << "unsuccessful" << endl;
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