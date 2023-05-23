#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& v, int L, int R, int k) {
	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(k == v[mid])
			return mid;
		else if(k > v[mid])
			L = mid + 1;
		else
			R = mid - 1;
	}

	return -1;
}

int getMaxInBitonicArray(vector<int>& v) {
	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(mid > 0 && mid < n - 1) {
			if(v[mid] > v[mid + 1] && v[mid] > v[mid - 1]) {
				return mid; // this is peak element in bitonic array
			} else if(v[mid + 1] > v[mid]) {
				L = mid + 1;
			} else if(v[mid - 1] > v[mid]) {
				R = mid - 1;
			}

		} else if(mid == 0) {
			if(v[mid] > v[mid + 1]) {
				return mid;
			} else {
				return mid + 1;
			}

		} else if(mid == n - 1) {
			if(v[mid] > v[mid - 1]) {
				return mid;
			} else {
				return mid - 1;
			}
		}
	}

	return -1;
}

int searchElementInBitonicArray(vector<int>& v, int k) {
	// 1: find peak element
	// 2: array is divided in increasing and decreasing, now search the element
	int n = v.size();
	int maxIdx = getMaxInBitonicArray(v);
	int lsearch = binarySearch(v, 0, maxIdx - 1, k);
	int rsearch = binarySearch(v, maxIdx, n - 1, k);

	if(lsearch == -1)
		return rsearch;
	return lsearch;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 3, 8, 12, 4, 2};
	int k = 8;
	cout << searchElementInBitonicArray(v, k) << '\n';

	return 0;
}