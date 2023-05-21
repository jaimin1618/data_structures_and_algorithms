#include<bits/stdc++.h>
using namespace std;

/*
find floor of element in sorted array, floor is simply element below that if not found
[1, 2, 4, 6, 8], k = 5
floor of k=5 in given array is 4

you can also say floor is lower bound index - 1
*/

int find_floor_element(vector<int>& v, int k) {
	int n = v.size();
	int L = 0, R = n - 1;
	int result = -1;

	while(L <= R) {
		int mid = L + (R - L) / 2;
		if(k == v[mid])
			return v[mid];

		else if(k > v[mid]) {
			// is candidate
			result = v[mid];
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> v {2, 3, 4, 7, 12, 16, 20};
	int k = 11; // ans = 7;

	cout << find_floor_element(v, k) << '\n';



	return 0;
}