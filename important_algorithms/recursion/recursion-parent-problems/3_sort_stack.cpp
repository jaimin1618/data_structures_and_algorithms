#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int k) {
	if(s.size() == 0 || s.top() < k) {
		s.push(k);
		return;
	}
	
	int tmp = s.top();
	s.pop();
	insert(s, k);
	s.push(tmp);
}

void sortStack(stack<int>& s) {
	int n = (int) s.size();
	if(n == 1 || n == 0) 
		return;
	
	int tmp = s.top();
	s.pop();
	sortStack(s);
	insert(s, tmp);
}

void printStack(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}
		
int main() {
	stack<int> s;
	s.push(3);
	s.push(5);
	s.push(1);
	s.push(4);
	s.push(2);
	
	printStack(s);
	sortStack(s);
	printStack(s);
			
	return 0;
}
