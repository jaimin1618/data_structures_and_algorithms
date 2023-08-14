#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int value;
}

int maxPathSum(Node *root, int result) {
	if(root == nullptr)
		return 0;

	int l = maxPathSum(root->left, result);
	int r = maxPathSum(root->right, result);

	int temp = max(root->value, root->value + max(l, r));
	int ans = max(temp, l + r + root->value);
	result = max(result, ans);  

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}