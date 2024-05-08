#include "Utility.h"

void initializeTree(TreeNode* &root) {
	std::ifstream inFS("TreeData.txt");

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
		}
	}

/*
try {
		if (!inFS) throw string("File Open Error");
		else {
		}
	}
	catch (string message) {
		std::cout << message;
		exit(0);
}
*/
}


//!!!RECURSIVE FUNCTION!!! GET SERIOUS !!!
TreeNode* navigateToDirectory(TreeNode*& node, string key) {
	std::vector<TreeNode*> children = node->getChildren();		//iterate through all of current node's children until match found
	for (int i = 0; i < children.size(); ++i) {					//if not, go one layer deeper
		TreeNode* currNode = children[i];
		if (key == currNode->getData()) {
			return currNode;
		}
	}
}