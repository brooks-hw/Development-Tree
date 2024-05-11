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
        bool running = handleInput(userInput, currDirectory);
        if (running != true) break;     //happens if user types 'quit'
    }

    delete root;
    

}

