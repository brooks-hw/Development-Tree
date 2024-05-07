#include "Tree.h"

Tree::Tree() {
	this->root = nullptr;
}

Tree::Tree(TreeNode* root) {
	this->root = root;
}

TreeNode* Tree::getRoot() {
	return this->root;
}

void Tree::setRoot(TreeNode* root) {
	this->root = root;
}

void Tree::insertNode(TreeNode* &node) {
	
}

void Tree::deleteNode(TreeNode*& node) {

}