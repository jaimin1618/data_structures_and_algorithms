#include<bits/stdc++.h>
using namespace std;

int indexOfOne(vector<int>& v) {
	// using STL
	const vector<int>::iterator it = lower_bound(v.begin(), v.end(), 1);
	return distance(v.begin(), it);
}

int infinitBinearySearch(vector<int>& v) {
	int n = v.size();
	int L = 0, R = 1;
	const int K = 1;

	while(R < n && v[R] < K) {
		L = R;
		R *= 2;
	}

	// we found the range, [L, R]
	int result = -1;
	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(K == v[mid]) {
			// K >= v[mid] OR K == v[mid] both are same because 0, 1 el only
			result = mid;
			R = mid - 1;
		}
		else if(K > v[mid]) 
			L = mid + 1;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// consider our binary sorted infinite array
	vector<int> v {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	cout << indexOfOne(v) << '\n';
	cout << infinitBinearySearch(v) << '\n';

	return 0;
}