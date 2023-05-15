#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}

void printReverser(stack<int>& s) {
	if(s.empty())
		return;
		
	int tmp = s.top();
	s.pop();
	printReverser(s);
	s.push(tmp);
}

void insertAtBottom(stack<int>& s, int k) {
	if(s.empty()) {
		s.push(k);
		return;
	}
		
	int tmp = s.top();
	s.pop();
	insertAtBottom(s, k);
	s.push(tmp);
}

void reverseInMemory(stack<int>& s) {
	if(s.empty())
		return;
	
	int tmp = s.top();
	s.pop();
	reverseInMemory(s);
	insertAtBottom(s, tmp);
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	
	print(s);
	reverseInMemory(s);
	print(s);


	return 0;
}
