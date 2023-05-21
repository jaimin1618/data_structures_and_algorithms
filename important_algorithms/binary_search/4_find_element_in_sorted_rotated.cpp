#include<bits/stdc++.h>
using namespace std;

/**
 * Q: find element in sorted but rotated array
 * A: 
 * 1. find index of minimum element
 * (array is sorted before and after that)
 * 2. then apply BS on both sides 
 */

int binarySearch(vector<int>& v, int L, int R, int k) {
	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(k == v[mid])
			return mid;
		else if(k < v[mid])
			R = mid - 1;
		else
			L = mid + 1;
	}

	return -1;
}

// get index of min element
int getMin(vector<int>& v) {
	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;
		// don't forget to put "(" ")" for modulo of negative number
 		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;

		if(v[mid] < prev && v[mid] < next)
			return mid; // this is min element
		else if(v[0] <= v[mid])
			L = mid + 1;
		else if(v[mid] <= v[n - 1])
			R = mid - 1;
	}

	return 0;
}

// main function to find element in rotated array using BS
int findInRotatedIndex(vector<int>& v, int K) {
	int n = v.size();
	int min_idx = getMin(v);
	int check_left = binarySearch(v, 0, min_idx - 1, K);
	int check_right = binarySearch(v, min_idx, n - 1, K);

	if(check_left == -1)
		return check_right;
	return check_left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {11, 12, 15, 18, 2, 5, 6, 8};
	int key = 5;

	for(auto& el: v) {
		cout << findInRotatedIndex(v, el) << '\n';
	}

	

	return 0;
}