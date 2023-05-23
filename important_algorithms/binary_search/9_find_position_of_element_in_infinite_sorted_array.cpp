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

int infinitBinearySearch(vector<int>& v, int k) {
	int n = v.size();
	int L = 0;
	int R = 1;

	while(R < n && k > v[R]) {
		L = R;
		R *= 2;
	}

	return binarySearch(v, L, R, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// consider this is infinite array
	vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	for(auto& el: v) 
		cout << infinitBinearySearch(v, el) << '\n';

	cout << infinitBinearySearch(v, 100) << '\n';
	

	return 0;
}