#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* left = nullptr;
	Node* right = nullptr;
};

int solve(Node *root, int& result) {
	if(root == nullptr)
		return 0;

	int left_height = solve(root->left, result);
	int right_height = solve(root->right, result);

	int temp = 1 + max(left_height, right_height);
	int ans = max(temp, 1 + left_height + right_height);
	result = max(result, ans); // update answer if current answer is best answer

	// pass current (temporary result) to parent node
	return temp;
}

int diameter(Node *root) {
	int result = INT_MIN;
	solve(root, result);
	return result;
}


/*============================
ANOTHER SOLUTION | Explanable solution, from updating height of binary tree code
============================*/
int height(Node *root) {
	if(root == nullptr)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	return 1 + max(lh, rh);
}

int ans = INT_MIN;
int diameterFromHeight(Node *root) {
	if(root == nullptr)
		return 0;

	int lh = diameterFromHeight(root->left);
	int rh = diameterFromHeight(root->right);

	// update diameter if current node gives longest diameter of tree
	// equation for tree diameter = 1 + Height of left tree + Height of right tree
	ans = max(ans, 1 + lh + rh);

	return 1 + max(lh, rh);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node* root = new Node();
	root->left = new Node();
	root->left->left = new Node();
	root->left->right = new Node();
	root->right = new Node();

	cout << diameter(root) << '\n';





	
	return 0;
}