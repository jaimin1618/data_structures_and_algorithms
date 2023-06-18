#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int>& s) {
	if(s.size() == 1)
		return;

	int top = s.top();
	s.pop();
	sortStack(s);

	stack<int> tmp;
	while(!s.empty() && s.top() > top) {
		tmp.push(s.top());
		s.pop();
	}

	s.push(top);

	while(!tmp.empty()) {
		s.push(tmp.top());
		tmp.pop();
	}
}

// complete recursive solution
void insert(stack<int>& s, int item) {
	if(s.empty() || item >= s.top()) {
		s.push(item);
		return;
	}

	else if(s.top() > item) {
		int currentTop = s.top();
		s.pop();
		insert(s, item);
		s.push(currentTop);
	}
}

// 4, 2, 1, 5, 3
// 1, 2, 4, 5 | insert: 3

void completeRecursiveSolution(stack<int>& s) {
	if(s.size() == 1)
		return;

	int top = s.top();
	s.pop();
	sortStack(s);
	insert(s, top);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {5, 1, 0, 2};
	stack<int> s;
	for(auto& el: v)
		s.push(el);

	completeRecursiveSolution(s);
	while(!s.empty()) {
		cout << s.top() << '\n';
		s.pop();
	}

	
	return 0;
}