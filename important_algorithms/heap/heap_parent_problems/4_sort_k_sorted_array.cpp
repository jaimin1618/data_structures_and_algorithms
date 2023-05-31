#include<bits/stdc++.h>
using namespace std;

/**
 * Most important question for Heap
 * Sort nearly sorted array, asked in F2F@flipkart
 */

void sortKSortedArray(vector<int>& v, int k) {
	priority_queue<int,vector<int>,greater<int>> minHeap;
	vector<int> sorted_v;

	for(int i = 0; i < v.size(); ++i) {
		minHeap.push(v[i]);
		if(minHeap.size() > k) {
			int top = minHeap.top();
			sorted_v.push_back(top);
			minHeap.pop();
		}
	}

	while(!minHeap.empty()) {
		sorted_v.push_back(minHeap.top());		
		minHeap.pop();
	}

	v.assign(sorted_v.begin(), sorted_v.end());
} 

int main() {
	vector<int> v{6, 5, 3, 2, 8, 10, 9};
	int k = 3;
	sortKSortedArray(v, k);
	for(int& el: v)
		cout << el << ' ';

	return 0;
}
