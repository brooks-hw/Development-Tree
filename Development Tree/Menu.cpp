#include "Menu.h"

void handleInput(Tree*& rootDirectory) {
	std::string userInput;
	TreeNode* currDirectory = rootDirectory->getRoot();
	while (true) {
		writeCurrentDirectory(currDirectory);
		std::getline(std::cin, userInput);
		int choice = convertInput(userInput);
	}
}

int convertInput(string userInput) {
	if (userInput == "mkdir") {

	}
}

void writeCurrentDirectory(TreeNode*& currDirectory) {
	std::stack<string> directoryList;
	while (currDirectory->getData() != "~") {
		directoryList.push(currDirectory->getData());
		currDirectory = currDirectory->getParent();
	}
	std::cout << " ~";
	while (!directoryList.empty()) {
		std::cout << "/" << directoryList.top();
		directoryList.pop();
	}
	cout << "\n$ ";
}