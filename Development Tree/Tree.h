#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree {
private:

	TreeNode* root;

public:

	Tree();
	Tree(TreeNode* root);
	TreeNode* getRoot();
	void insertNode(TreeNode* &node);
	void deleteNode(TreeNode* &node);
};

#endif