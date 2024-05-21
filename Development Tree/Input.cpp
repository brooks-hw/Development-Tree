#include "Input.h"

string gatherInput(TreeNode*& currDirectory) {
	string userInput;
	bool validCommand;

	while (true) {
		writeCurrDirectory(currDirectory);

		//gather user input, process user's command, then check for validity
		std::getline(std::cin, userInput);
		string command = processCommand(userInput);
		bool validCommand = checkValid(command);

		//if command is valid, it is returned to main() for processing
		if (validCommand) {
			return userInput;
		}
		else {
			cout << "Error: \"" << command << "\" is not a valid command\n\n";
		}
	}
}

bool handleInput(string userInput, TreeNode*& currDirectory) {
	string command, argument;

	//determine if the command contains an argument or is simply a listing command
	if (userInput.find(" ") != std::string::npos) {
		command = userInput.substr(0, userInput.find(" "));
		argument = userInput.substr(userInput.find(" ") + 1);
	}
	else {		//command contains no spaces indicating its just a listing command
		command = userInput;
	}

	//command is then passed to getChoice() to determine which operation to carry out
	int choice = getChoice(command);

	switch (choice) {
	case 0: {
		cout << "\nExiting...";
		return false;
	}
	case 1: {	//(mkdir) 
		TreeNode* newDirectory = currDirectory->addNode(argument);		//create new node with current argument
		writeToFile(newDirectory);			//write node's data to TreeData.txt
		return true;
	}
	case 2: {	//(dir) 
		currDirectory->listChildren();
		return true;
	}
	case 4: {	//(cd)
		TreeNode* newDirectory = currDirectory->changeDirectory(argument);
		//nullptr indicates argument doesn't exist in this directory
		if (newDirectory != nullptr) {
			currDirectory = newDirectory;
		}
		else std::cout << "Error \"" << argument << "\" does not exist in this directory\n\n";
		return true;
	}
	case 5: {	//(help)
		cout << "Fuck you\n";
		return true;
	}
	}
}

void writeCurrDirectory(TreeNode* currDirectory) {
	//start with some fun system user text (even tho its not real)
	std::cout << "Brooks@DESKTOP-6TCKLMF Dev-Tree";
	std::stack<string> directoryList;

	TreeNode* tempDirectory = currDirectory;
	//a stack is used in order to be able to "reverse" the elements (because we start with our currentDirectory and work up)
	while (tempDirectory->getData() != "~") {	//elements are added until root directory is reached
		directoryList.push(tempDirectory->getData());
		tempDirectory = tempDirectory->getParent();
	}
	std::cout << " ~";	
	while (!directoryList.empty()) {	//starting with the root, output all parent directories up until currDirectory
		std::cout << "/" << directoryList.top();
		directoryList.pop();
	}
	std::cout << "\n$ ";
}

int getChoice(string command) {
	//function to process command into integer request
	if (command == "quit") return 0;
	else if (command == "mkdir") return 1;
	else if (command == "dir") return 2;
	else if (command == "find") return 3;
	else if (command == "cd") return 4;
	else if (command == "help") return 5;
	else return 5;	//"delete"
}

string processCommand(string userInput) {
	//extracts command from userInput, if command contains a space it contains an argument
	if (userInput.find(" ") != std::string::npos) {
		return userInput.substr(0, userInput.find(" "));
	}
	else {	//otherwise the command is simply just the input
		return userInput;
	}
}

bool checkValid(string command) {	
	//command validity is checked before input is handled, therefore we won't have to worry about it during processing
	if (command == "quit" || command == "mkdir" || command == "dir" || command == "cd") {
		return true;
	}
	else return false;
}

