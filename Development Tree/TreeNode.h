#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cout;

class TreeNode {
private:
	std::string data;
	std::vector<TreeNode*> children;
	TreeNode* parent;

public:
	TreeNode();
	TreeNode(string data);
	TreeNode(string data, TreeNode* parent);

	void setData(string data);
	string getData();
	std::vector<TreeNode*>& getChildren();
	TreeNode* getParent();

};

#endif