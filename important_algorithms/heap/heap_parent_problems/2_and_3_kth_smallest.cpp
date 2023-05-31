#include<bits/stdc++.h>
using namespace std;

/**
 * Smallest => Max heap
 * Largest => Min heap
 */

int kth_smallest(int v[], int n, int k) {
	priority_queue<int> maxH;
	// kth "smallest" => "max" heap

	for(int i = 0; i < n; ++i) {
		maxH.push(v[i]);
		if(maxH.size() > k) {
			maxH.pop();
		}
	}

	return maxH.top();
}

int kth_largest(int v[], int n, int k) {
	// kth "largrest" => "min" heap
	priority_queue<int,vector<int>,greater<int>> minH;

	for(int j = 0; j < n; ++j) {
		minH.push(v[j]);
		if(minH.size() > k) {
			minH.pop();
		}
	}

	return minH.top();
}

int main() {
	int v[]{7, 10, 4, 3, 20, 15};
	int n = sizeof(v) / sizeof(int);
	int k = 3;
	int result = kth_smallest(v, n, k);
	cout << result << '\n';
	result = kth_largest(v, n, k);
	cout << result << '\n';


	return 0;
}