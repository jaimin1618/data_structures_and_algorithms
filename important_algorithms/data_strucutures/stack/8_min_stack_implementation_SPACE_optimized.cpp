#include<bits/stdc++.h>
using namespace std;

/**
 * Min stack implementation using O(1)
 */
int minElement = -1;
stack<int> s;		

void push(int item) {
	if(s.empty()) {
		s.push(item);
		minElement = item;
	} else {
		if(item >= minElement)
			s.push(item);
		else {
			s.push(2 * item - minElement);
			minElement = item;
		}
	}
};

void pop() {
	if(s.empty()) {
		cout << "[ERROR]: Stack is empty" << '\n';
		return;
	} else {
		if(s.top() >= minElement) 
			s.pop();
		else {
			minElement = 2 * minElement + s.top();
			s.pop();
		}
	}
};

int top() {
	if(!s.empty()) {
		if(s.top() >= minElement)
			return s.top();
		else
			return minElement;
	}

	return -1;
};

int getMin() {
	if(s.empty())
		return -1;
	return minElement;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	return 0;
}