#include<bits/stdc++.h>
using namespace std;

int find_ceil_element(vector<int>& v, int k) {
	int n = v.size();
	int L = 0, R = n - 1;
	int result = -1;

	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(k == v[mid])
			return v[mid];
		else if (k > v[mid]) {
			L = mid + 1;	
		} else {
			result = v[mid];
			R = mid - 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> v {2, 3, 4, 7, 12, 16, 20};
	int k = 11; // ans = 12;

	cout << find_ceil_element(v, k) << '\n';



	return 0;
}