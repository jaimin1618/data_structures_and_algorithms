#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int v;
};

int solve(Node* root, int result) {
	if(root == nullptr)
		return 0;

	int l = solve(root->left, result);
	int r = solve(root->right, result);

	int temp = root->v + max(l, r);
	if(root->left == nullptr && root->right == nullptr)
		temp = max(temp, root->v);
	int ans = max(temp, l + r + root->v);
	result = max(result, ans);

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}