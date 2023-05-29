#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& v) {
	// [1, 3, 2, 4] => [-1, 2, -1, -1] 
	const int n = v.size();
	vector<int> res;
	stack<int> s;

	for(int i = n - 1; i >= 0; --i) {
		if(s.empty())
			res.push_back(-1);

		else if(!s.empty() && s.top() < v[i]) 
			res.push_back(s.top());

		else if(!s.empty() && s.top() > v[i]) {

			while(!s.empty() && s.top() > v[i])
				s.pop();

			if(s.empty())
				res.push_back(-1);
			else
				res.push_back(s.top());

		}

		s.push(v[i]);
	}

	reverse(res.begin(), res.end());
	return res;
}

vector<int> previousSmallerElement(vector<int>& v) {
	// [1, 3, 2, 4] => [-1, 1, 1, 2] 
	const int n = v.size();
	vector<int> res;
	stack<int> s;

	for(int i = 0; i < n; ++i) {
		if(s.empty())
			res.push_back(-1);

		else if(!s.empty() && s.top() < v[i])
			res.push_back(s.top());

		else if(!s.empty() && s.top() >= v[i]) {

			while(!s.empty() && s.top() >= v[i])
				s.pop();

			if(s.empty())
				res.push_back(-1);
			else
				res.push_back(s.top());
		}

		s.push(v[i]);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v { 1, 3, 2, 4 };
	
	vector<int> result = nextSmallerElement(v);
	for(auto& el: result)
		cout << el << ' ';
	cout << '\n';

	vector<int> presult = previousSmallerElement(v);
	for(auto& el: presult)
		cout << el << ' ';
	cout << '\n';

	vector<int> t {4, 5, 2, 10, 8};
	for(auto el: previousSmallerElement(t))
		cout << el << ' ';
	cout << '\n';

	return 0;
}