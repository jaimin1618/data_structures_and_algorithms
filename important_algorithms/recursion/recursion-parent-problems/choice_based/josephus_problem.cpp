#include<bits/stdc++.h>
using namespace std;

void printv(vector<int>& v) {
	for(int& el: v)
		cout << el << ' ';
	cout << '\n';
}

void solve(int k, int index, vector<int>& v) {
	if(v.size() == 1) {
		return;
	}

	index = (index + k) % v.size();
	v.erase(v.begin() + index);
	solve(k, index, v);
}

int josephus_problem(int n, int k) {
	vector<int> persons(n);
	for(int i = 0; i < n; ++i)
		persons[i] = i + 1;
			
	int index = 0;
	k -= 1;
	solve(k, index, persons);
	return persons[0];
}

int main() {
	vector<vector<int>> v = {
		{5, 2},
		{40, 7},
		{10, 2}
	};
	
	for(vector<int>& el: v) {
		int n = el[0];
		int k = el[1];
		cout << josephus_problem(n, k) << '\n';
	}

	return 0;
}
