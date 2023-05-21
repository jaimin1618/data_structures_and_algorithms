#include<bits/stdc++.h>
using namespace std;

/**
 * Q: find number of times sorted array was rotated
 * A: Number of times array is rotated = index of minimum element (first element when array was not rotated)
 * 
 */

int count_rotations(vector<int>& v) {
	// 1st: times rotation = index of minimum element (that is smaller than both of its neighbours)
	// 2nd: We will find minimum element in unsorted side of array
	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;
		int next = v[(mid + 1) % n];
		int prev = v[(mid + n - 1) % n];

		// condition for mid
		if(v[mid] < next && v[mid] < prev)
			return mid; // found the min element

		else if(v[0] <= v[mid])
			L = mid + 1;
		else if(v[mid] <= v[n - 1])
			R = mid - 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> v {2, 5, 6, 8, 11, 12, 15, 18};
	vector<int> rotated4times {11, 12, 15, 18, 2, 5, 6, 8};
	vector<int> rotated1times {5, 6, 8, 11, 12, 15, 18, 2};

	// index of "2" is the answer
	// now we can do linear search but => O(n);
	// so we need to implement binary search => O(logn);
	cout << "number of times rotated: " << count_rotations(v) << '\n';
	cout << "number of times rotated: " << count_rotations(rotated4times) << '\n';
	cout << "number of times rotated: " << count_rotations(rotated1times) << '\n';





	return 0;
}