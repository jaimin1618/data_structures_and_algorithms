#include<bits/stdc++.h>
using namespace std;

/**
 * Interesting new pattern for Heap
 */

// find the sum between k1th and k2th smallest numbers excluding k1th and k2th smallest
int getKthSmallest(vector<int>& v, int k) {
	priority_queue<int> maxH;

	for(auto& el: v) {
		maxH.push(el);

		if(maxH.size() > k)
			maxH.pop();
	}

	return maxH.top();
}

int sumNumbersBetweenK1thK2thSmallest(vector<int>& v, int k1, int k2) {
	int first = getKthSmallest(v, k1);
	int second = getKthSmallest(v, k2);
	int sum = 0;

	for(int& el: v) 
		if(el > first && el < second) 
			sum += el;

	return sum;
}

int main() {
	vector<int> v {1, 3, 12, 5, 15, 11};
	int k1 = 3;
	int k2 = 6;
	cout << sumNumbersBetweenK1thK2thSmallest(v, k1, k2) << '\n';



	return 0;
}