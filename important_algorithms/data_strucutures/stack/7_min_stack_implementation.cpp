#include<bits/stdc++.h>
using namespace std;

/**
 * Implementing Min Stack with,
 * - Extra Space
 * - Optimizing it to O(1) space
 * 
 * We will implement .PUSH(), .POP() and .GET_MIN_ELE() operations
 */
stack<int> s; // main stack to store elements
stack<int> ss; // supporting stack (ss) to store min element of stack

void push(int item) {
	s.push(item);

	if(ss.empty() || ss.top() >= item)
		ss.push(item);
};

int pop() {
	if(s.empty()) {
		cout << "[ERROR]: Stack is empty\n" << '\n';
		return -1;
	}

	int t = s.top();
	s.pop();

	if(t == ss.top())
		ss.pop();

	return t;
};

int getMin() {
	if(ss.empty()) {
		cout << "[ERROR]: Stack is empty\n" << '\n';
		return -1;
	}

	return ss.top();
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {18, 19, 29, 15, 16, 15};

	for(auto& el: v) {
		push(el);
		int minEl = getMin();
		cout << "current min: " << minEl << '\n';
	}

	return 0;
}