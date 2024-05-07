#include "Utility.h"

Tree* initializeDirectories() {
	Tree* rootDirectory = new Tree();
	TreeNode* root = new TreeNode("~");
	rootDirectory->setRoot(root);
	return rootDirectory;
}
