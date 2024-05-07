#include <iostream>
#include "Utility.h"
#include "Menu.h"
#include "Tree.h"

int main() {
    
    Tree* rootDirectory = initializeDirectories();
    handleInput(rootDirectory);
    /*
    TreeNode* child1 = new TreeNode("directory1", rootDirectory->getRoot());
    TreeNode* root = rootDirectory->getRoot();
    root->addChild(child1);
    */
    //example of adding a child 

    /*
    while (true) {
        gatherInput(rootDirectory);
    }
    */

    delete rootDirectory;
}

