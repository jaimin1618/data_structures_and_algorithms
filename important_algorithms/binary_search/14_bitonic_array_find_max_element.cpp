#include<bits/stdc++.h>
using namespace std;

/**
 * What is bitonic array,
 * Bitonic array is monotonically increasing and then monotonically decreasing array
 */

int findMaxFromBitonicArray(vector<int>& v) {
	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(mid > 0 && mid < n - 1) {
			if(v[mid] > v[mid + 1] && v[mid] > v[mid - 1]) {
				return v[mid];
			} else if(v[mid + 1] > v[mid]) {
				L = mid + 1;
			} else if(v[mid - 1] > v[mid]) {
				R = mid - 1;
			}
		} else if(mid == 0) {
			if(v[mid] > v[mid + 1]) {
				return v[mid];
			} else {
				return v[mid + 1];
			}
		} else if(mid == n - 1) {
			if(v[n - 1] > v[n - 2]) {
				return v[n - 1];
			} else {
				return v[n - 2];
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> bitonic {1, 3, 8, 12, 4, 2};
	cout << findMaxFromBitonicArray(bitonic) << '\n';


	return 0;
}