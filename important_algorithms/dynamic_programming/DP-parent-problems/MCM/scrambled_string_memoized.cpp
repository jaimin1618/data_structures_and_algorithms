#include<bits/stdc++.h>
using namespace std;

void fn(const vector<int>& v) {
	for(const int& el: v) 
		cout << el << ' ';
	cout << '\n';
}

int main() {
	vector<int> v {1, 2, 3};
	do {
		fn(v);
	} while(next_permutation(v.begin(), v.end()));


	return 0;
}