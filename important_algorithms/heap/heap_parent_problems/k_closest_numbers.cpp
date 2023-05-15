#include<bits/stdc++.h>
using namespace std;

void printv(vector<int>& v) {
	for(int& el: v) 
		cout << el << ' ';
	cout << '\n';
}

/**
 * Find k closest numbers to given number:
 * Find k closest numbers to 7 in below example
 */

vector<int> k_closest_numbers(vector<int>& v, int number, int k) {
	const int n = (int) v.size();
	priority_queue<pair<int,int>> q; // max-Heap

	for(int i = 0; i < n; ++i) {
		int diff = abs(v[i] - number);
		auto p = make_pair(diff, v[i]); 
		q.push(p);
		if(q.size() > k) {
			q.pop();
		}
	}

	vector<int> result;
	while(!q.empty()) {
		auto p = q.top();
		result.push_back(p.second);
		q.pop();
	}

	return result;
}

int main() {
	vector<int> v{5, 6, 7, 8, 9};
	int k = 3;
	int x = 7;
	
	vector<int> result = k_closest_numbers(v, x, k);
	printv(result);

	return 0;
}

/**
NOTE:
priority_queue<pair<int,int>> q;
this will be default maxHeap with KEY as comparator;
here we have taken difference as comparator for sorting & storing
*/