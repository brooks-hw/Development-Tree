#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree {
private:

	TreeNode* root;
	int nodeCount;

public:

	Tree();
	Tree(TreeNode* root);
	TreeNode* getRoot();
	void setRoot(TreeNode* root);
	void insertNode(TreeNode* &node);
	void deleteNode(TreeNode* &node);

};

#endif