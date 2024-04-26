#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <vector>
using std::string;

class TreeNode {
private: 
	std::vector<string> data;
	std::vector<TreeNode*> children;
	TreeNode* parent;

public:
	TreeNode();
	TreeNode(std::vector<string> data, TreeNode* parent, std::vector<TreeNode*> children);

	void setData();
	std::vector<TreeNode*> getData();
	std::vector<TreeNode*> getChildren();
	TreeNode* getParent();

};

#endif