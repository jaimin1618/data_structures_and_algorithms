#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& v, int key) {
	int n = v.size();
	int L = 0, R = n - 1;
	int res = -1;

	while(L <= R) {
		int mid = L + (R - L) / 2;
		if(key == v[mid]) {
			res = mid;
			R = mid - 1;
		}
		else if(key > v[mid])
			L = mid + 1;
		else if(key < v[mid])
			R = mid - 1;
	}

	return res;
}

int upper_bound(vector<int>& v, int key) {
	int n = v.size();
	int L = 0, R = n - 1;
	int res = -1;

	while(L <= R) {
		int mid = L + (R - L) / 2;
		if(key == v[mid]) {
			res = mid;
			L = mid + 1;
		}
		else if(key > v[mid])
			L = mid + 1;
		else if(key < v[mid])
			R = mid - 1;
	}

	return res;
}

int get_count(vector<int>& v, int key) {
	int lower = lower_bound(v, key);
	int upper = upper_bound(v, key);
	return upper - lower + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {2, 4, 4, 10, 10, 10, 19, 20, 20};
	int LB = lower_bound(v, 10);
	int UB = upper_bound(v, 10);
	cout << LB << " " << UB << '\n';
	cout << "count of 10: " << get_count(v, 10) << '\n';
	

	return 0;
}