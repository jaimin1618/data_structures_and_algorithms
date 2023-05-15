#include<bits/stdc++.h>
using namespace std;

/**
 * Find a path from root to Leaf node
 * such that there is no "0" in path 
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val): val(_val) {};	
};

bool pathExists(TreeNode *root) {
	if(root == NULL || root->val) 
		return false;

	if (root->left == NULL && root->right == NULL) 
		return true;
	if(pathExists(root->left))
		return true;
	if(pathExists(root->right))
		return true;

	return false;
}

bool pathToLeaf(TreeNode *root, vector<int>& path) {
	if(root == NULL || root->val == 0) 
		return false;
	path.push_back(root->val);

	if(root->left == NULL && root->right == NULL)
		return true;
	if(pathToLeaf(root->left, path)) 
		return true;
	if(pathToLeaf(root->right, path))
		return true;

	// backtracking
	path.pop_back();
	return false;
}

int main() { 

	return 0;
}