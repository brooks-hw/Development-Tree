#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <stack>
#include "TreeNode.h"
#include "Utility.h"

using std::cout;
using std::string;

string gatherInput(TreeNode* &currDirectory);
bool handleInput(string userInput, TreeNode*& currDirectory);
void writeCurrDirectory(TreeNode* currDirectory);

int getChoice(string command);
string processCommand(string userInput);
bool checkValid(string command);


#endif