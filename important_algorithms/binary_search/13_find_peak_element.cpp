#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& v) {
	/**
	 * - Find and return index of Peak Element 
	 * - What is Peak element, Peak element means element that is greater than both of its neighbours
	 * - there can be multiple peak elements, return any
	 * - last elements are considered peak element if they are greater than their one neighbour
	 */

	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(mid > 0 && mid < n - 1) {
			if(v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
				return mid;
			} else if(v[mid - 1] > v[mid + 1]) {
				R = mid - 1;
			} else {
				L = mid + 1;
			}
		} else if(mid == 0) {
			if(v[mid] > v[mid + 1])
				return 0;
			else
				return 1;
		} else if(mid == n - 1) {
			if(v[n - 1] > v[n - 2]) {
				return n - 1;
			} else {
				return n - 2;
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 2, 100, 20, 5, 10, 20, 15}; // unsorted element 
	cout << findPeakElement(v) << '\n';

	return 0;
}