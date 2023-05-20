#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int value;
	ListNode *next;
	ListNode(int _value): value(_value), next(NULL) {};
};

void insert(ListNode *root, int item) {
	while(root->next != NULL) 
		root = root->next;
	root->next = new ListNode(item);
}

void display(ListNode *root) {
	if(root == NULL) 
		cout << "[EMPTY]" << '\n';
	while(root != NULL) {
		cout << root->value << ' ';
		root = root->next;
	}
}

ListNode *getMiddleNode(ListNode *root) {
	// fast / slow pointer method
	ListNode *fast = NULL, *slow = NULL;
	fast = root;
	slow = root;

	// fast != NULL is same as fast
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

bool isCycleInList(ListNode *root) {
	ListNode *fast = NULL, *slow = NULL;
	fast = root;
	slow = root;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast) 
			return true;
	}

	return false;
}

ListNode *getCycleHeadInList(ListNode *root) {
	ListNode *fast = NULL, *slow = NULL;
	fast = root;
	slow = root;
	bool isCycleFound = false;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast) {
			isCycleFound = true;
			break;
		} 
	}

	if(!isCycleFound) 
		return NULL;

	ListNode *slow2 = root;
	while(slow != slow2) {
		slow = slow->next;
		slow2 = slow2->next;
	}

	return slow;
}

int main() {
	ListNode *root = new ListNode(1);

	insert(root, 2);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	insert(root, 6);

	display(root);

	ListNode *middle = NULL;
	middle = getMiddleNode(root);
	cout << "middle element: " << middle->value << '\n';



	return 0;
}