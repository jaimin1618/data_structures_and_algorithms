#include<bits/stdc++.h>
#define END cout << '\n'
using namespace std;

class BTree {
public:
	class TreeNode {
	public:
		int val = 0;
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		TreeNode(int _val): val(_val) {}
	};

	// public
	TreeNode *root = NULL;

	BTree(int root_value) {
		root = new TreeNode(root_value);
	}

	static bool search(TreeNode *root, int val) {
		if(root == NULL) 
			return false;

		if(val == root->val) 
			return true;
		else if(val > root->val)
			return search(root->right, val);
		else
			return search(root->left, val);

		return false;
	}

	static TreeNode* insert(TreeNode *root, int val) {
		if(root == NULL)
			return new TreeNode(val);

		if(val > root->val) 
			root->right = insert(root->right, val);
		else if(val < root->val)
			root->left = insert(root->left, val);

		return root;
	}

	static TreeNode* minValueNode(TreeNode *root) {
		TreeNode *curr = root;
		while(curr != NULL && curr->left != NULL) 
			curr = curr->left;
		return curr;
	}

	static TreeNode* maxValueNode(TreeNode *root) {
		TreeNode *curr = root;
		while(curr != NULL && curr->right != NULL) 
			curr = curr->right;
		return curr;	
	}

	static TreeNode* remove(TreeNode *root, int val) {
		if(root == NULL) 
			return NULL;

		if(val > root->val) 
			root->right = remove(root->right, val);
		if(val < root->val)
			root->left = remove(root->left, val);
		else {
			if (root->left == NULL){
				return root->right;
			} else if(root->right == NULL) {
				return root->left;
			} else {
				TreeNode *minNode = minValueNode(root->right);
				root->val = minNode->val;
				root->right = remove(root->right, minNode->val);
			}
		}

		return root;
	}


	static void DFS_inorder(TreeNode *root) {
		if(root == NULL) 
			return;
		DFS_inorder(root->left);
		cout << root->val << ' '; // process the node
		DFS_inorder(root->right);
	}


	static void DFS_preorder(TreeNode *root) {
		if(root == NULL) 
			return;
		cout << root->val << ' '; // process the node
		DFS_preorder(root->left);
		DFS_preorder(root->right);
	}


	static void DFS_postorder(TreeNode *root) {
		if(root == NULL) 
			return;
		DFS_postorder(root->left);
		DFS_postorder(root->right);
		cout << root->val << ' '; // process the node
	}

	static void BFS(TreeNode *root) {
		queue<TreeNode*> q;

		if(root != NULL) 
			q.push(root);

		while(!q.empty()) {

			for(int i = 0; i < q.size(); ++i) {
				TreeNode *curr = q.front();
				q.pop();
				cout << curr->val << ' ';

				if(curr->left != NULL) 
					q.push(curr->left);
				if(curr->right != NULL) 
					q.push(curr->right);
			}			

		}
	}
};


int main() {
	BTree *btree = new BTree(4);
	BTree::insert(btree->root, 3);
	BTree::insert(btree->root, 6);
	BTree::insert(btree->root, 2);
	BTree::insert(btree->root, 5);
	BTree::insert(btree->root, 7);

	/**
	 * 		   /4\
	 * 		 3	  /6\
	 *     2	 5	 7	
	 */

	BTree::DFS_inorder(btree->root);
	END;
	BTree::DFS_preorder(btree->root);
	END;
	BTree::DFS_postorder(btree->root);
	END;
	BTree::BFS(btree->root);
	END;


	return 0;
}