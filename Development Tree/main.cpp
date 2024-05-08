#include <iostream>
#include "Utility.h"
#include "Input.h"
#include "TreeNode.h"

int main() {
    
    TreeNode* root = new TreeNode("~");     //create root directory 
    TreeNode* currDirectory = root;
    initializeTree(root);

    while (true) {
        string userInput = gatherInput(currDirectory);
        handleInput(userInput, currDirectory);
    }

    delete root;
    

}

