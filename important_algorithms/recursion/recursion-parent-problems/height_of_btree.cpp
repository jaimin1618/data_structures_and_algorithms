#include<bits/stdc++.h>
using namespace std;

// utilities
struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int d): data(d), left(nullptr), right(nullptr) {};
};
void inorder(Node *root) {
	if(root != nullptr) {
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
}
void preorder(Node *root) {
	if(root != nullptr) {
		cout << root->data << ' ';
		inorder(root->left);
		inorder(root->right);
	}
}
void postorder(Node *root) {
	if(root != nullptr) {
		inorder(root->left);
		inorder(root->right);
		cout << root->data << ' ';
	}
}
// === x ===

int treeHeight(Node *root) {
	if(root == nullptr) return 0;
	int lh = treeHeight(root->left);
	int rh = treeHeight(root->right);
	return 1 + max(lh, rh);
}

int main() {
	Node *root = new Node(10);
	Node *rleft = new Node(20);
	Node *rright = new Node(30);
	root->left = rleft;
	root->right = rright; 
	Node *rlleft = new Node(40);
	Node *rlright = new Node(50);
	root->left->left = rlleft;
	root->left->right = rlright;

	// about example tree	
	inorder(root);
	cout << '\n';
	preorder(root);
	cout << '\n';
	postorder(root); 
	cout << '\n';
	
	int height = treeHeight(root);
	cout << "Height: " << height << '\n';
	

	return 0;
}


