#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <stack>
#include "Tree.h"

using std::cout;
using std::string;

void handleInput(Tree* &rootDirectory);
int convertInput(string userInput);
void writeCurrentDirectory(TreeNode*& currDirectory);



#endif