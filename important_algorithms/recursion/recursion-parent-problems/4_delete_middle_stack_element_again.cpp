#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int k) {
	if(k == 1) {
		s.pop();
		return;
	}

	int top = s.top();
	s.pop();
	solve(s, k - 1);
	s.push(top);
}

void deleteMiddle(stack<int>& s) {
	int k = 1 + s.size() / 2;
	solve(s, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 2, 3, 4, 5};
	stack<int> s;
	for(auto& el: v)
		s.push(el);

	deleteMiddle(s);

	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	
	return 0;
}