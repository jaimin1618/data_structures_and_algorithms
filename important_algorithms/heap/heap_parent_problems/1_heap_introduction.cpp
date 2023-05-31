#include<bits/stdc++.h>
using namespace std;

/**
 * Heap identification, 
 * 
 * Find 2 keywords in problems, 
 * those are "K" and "Smallest or Largest"
 * if you see these 2 keywords, There are 95%-98% chances of Heap.
 * Another things is, Heap questions are based on sorting or similar to those 
 * 
 * Two types of Heap: MinH, and MaxH
 * if K + Smallest => MaxH
 * if K + Largest => MinH
 * 
 * minH means Smaller elements (min elements) on Top of Stack
 * maxH means Larger elements (max elements) on Top of Stack
 * 
 * using Heap we transfer nlogn => nlogk complexity
 */

int kth_largest(vector<int>& v, int k) {
	// largest => minH;
	priority_queue<int> minH;

	for(auto& el: v) {
		minH.push(el);

		if(minH.size() > k)
			minH.pop();
	}

	return minH.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// default is maxHeap
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	// when need to store priority and value both using pair<int,int>
	using pi = pair<int, int>;
	priority_queue<pi> maxPairHeap;
	priority_queue<pi, vector<pi>, greater<pi>> minPairHeap;

	// running kth_largest code
	vector<int> v {7, 10, 4, 3, 20, 15};
	int k = 3;
	// 3, 4, 7, 10, 15, 20
	cout << kth_largest(v, k) << '\n';




	return 0;
}