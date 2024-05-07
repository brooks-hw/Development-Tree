#include "TreeNode.h"

TreeNode::TreeNode() {
	this->data = "";
	this->parent = nullptr;
}

TreeNode::TreeNode(string data) {		//constructor for only the root directory
	this->data = data;
	this->parent = nullptr;
}

TreeNode::TreeNode(string data, TreeNode* parent) {
	this->data = data;
	this->parent = parent;
}

void TreeNode::setData(string data) {
	this->data = data;
}

string TreeNode::getData() {
	return this->data;
}

std::vector<TreeNode*>& TreeNode::getChildren() {
	return this->children;
}

TreeNode* TreeNode::getParent() {
	return this->parent;
}