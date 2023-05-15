#include<bits/stdc++.h>
using namespace std;

vector<int> k_largest_elements(vector<int>& arr, int k) {
	priority_queue<int,vector<int>,greater<int>> minHeap;

	for(int& el: arr) {
		minHeap.push(el);
		if(minHeap.size() > k) {
			minHeap.pop();
		}
	}

 	vector<int> v;
	while(!minHeap.empty()) {
		v.push_back(minHeap.top());
		minHeap.pop();
	}

	return v;
}

int main() {
	vector<int> v {7, 10, 4, 3, 20, 15};
	int k = 3;
	vector<int> kLargest = k_largest_elements(v, k);
	for(int& el: kLargest) {
		cout << el << ' ';
	}


	return 0;
}