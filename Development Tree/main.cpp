#include <iostream>
#include "Utility.h"
#include "Menu.h"
#include "Tree.h"

int main() {
    
    Tree* rootDirectory = initializeDirectories();
    //gatherInput(rootDirectory);
    delete rootDirectory;
}

