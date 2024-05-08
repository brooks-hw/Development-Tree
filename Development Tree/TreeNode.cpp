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

void TreeNode::addChild(TreeNode* child) {
	this->children.push_back(child);
}

void TreeNode::addNode(string data) {	
	//new directory is created with data, parent is set to 'this' which is memory address of called object
	TreeNode* newDirectory = new TreeNode(data, this);
	this->children.push_back(newDirectory);
	cout << "\n";
}

void TreeNode::listChildren() {
	//simply output data in 'children' vector
	for (int i = 0; i < children.size(); ++i) {
		std::cout << "-" << children[i]->getData() << std::endl;
	}
	cout << "\n";
}

TreeNode* TreeNode::changeDirectory(string directory) {
	for (int i = 0; i < children.size(); ++i) {
		TreeNode* currNode = children[i];
		if (directory == currNode->getData()) {
			return currNode;
		}
	}
	cout << "\nEntry doesn't exist in this directory";
}