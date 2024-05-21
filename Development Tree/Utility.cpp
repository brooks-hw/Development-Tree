#include "Utility.h"

void initializeTree(TreeNode* &root) {
	std::ifstream inFS("TreeData.txt");

	try {
		if (!inFS) throw string("File Open Error");
		else {
			TreeNode* currentDirectory = root;
			string currLine, parent, data;

			while (std::getline(inFS, currLine)) {
				data = currLine.substr(currLine.find(" ") + 1);
				parent = currLine.substr(0, currLine.find(" "));

				if (parent == currentDirectory->getData()) {	//if the current entry's parent is equal the the current directory's name:
					TreeNode* newNode = new TreeNode(data, currentDirectory);	//simply create a new directory and make its parent the currentDirectory
					currentDirectory->addChild(newNode);
				}
				else {		//otherwise the current entry's parent already exists in the tree and we must navigate to it update currentDirectory
					currentDirectory = navigateToDirectory(root, parent);
					TreeNode* newNode = new TreeNode(data, currentDirectory);
					currentDirectory->addChild(newNode);
				}
			}
			inFS.close();
		}
	}
	catch (string message) {
		std::cout << message;
		exit(0);
}

}

void writeToFile(TreeNode* node) {
	std::ifstream inFS("TreeData.txt");
	string currLine, parent, data;
	std::vector<string> oldData;

	while (std::getline(inFS, currLine)) {
		oldData.push_back(currLine);
	}
	inFS.close();

	for (int i = 0; i < oldData.size(); ++i) {
		cout << oldData[i] << "\n";
	}

	std::ofstream outFS("TreeData.txt");

	if (oldData.size() == 0) {
		string newLine = node->getParent()->getData() + " " + node->getData();
		oldData.insert(oldData.begin(), newLine);
	}

	auto currentPos = oldData.begin();
	for (int i = 0; i < oldData.size(); ++i) {
		parent = currLine.substr(0, currLine.find(" "));
		if (parent == node->getParent()->getData()) {
			string newLine = node->getParent()->getData() + " " + node->getData();
			oldData.insert(oldData.begin() + i, newLine);
		}
	}

	for (int i = 0; i < oldData.size(); ++i) {
		outFS << oldData[i] << "\n";
	}

	outFS.close();
	
	//need to find node's parent directory and insert the newLine of data somewhere in that directory
	//do this by storing the lines of data in a structure that has their parent and data
	//continue until same parent is found, from there insert data based on alphabetical order
	//write the new file with the contents of the modified data structure

}

TreeNode* navigateToDirectory(TreeNode*& node, string key) {
	std::vector<TreeNode*> children = node->getChildren();		//iterate through all of current node's children until match found
	for (int i = 0; i < children.size(); ++i) {					//if not, go one layer deeper
		TreeNode* currNode = children[i];
		if (key == currNode->getData()) {
			return currNode;
		}
	}
}