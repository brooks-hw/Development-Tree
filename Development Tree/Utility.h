#ifndef UTILTIY_H
#define UTILITY_H

#include <fstream>
#include <map>
#include "TreeNode.h"

void initializeTree(TreeNode* &root);
void writeToFile(TreeNode* node);
TreeNode* navigateToDirectory(TreeNode*& root, string key);






#endif