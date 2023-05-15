#include<bits/stdc++.h>
using namespace std;

/**
 * Find largrest subarray with same element value inside subarray
 * for e.g. {1, 2, 2, 3, 3, 3}
 * answer = 3
 * 
 */

// O(N^2)
int longest_subarray_same_value_brute_force(vector<int>& v) {
	const int N = v.size();
	int L = 0, R = 0;
	int maxLength = 0;

	for(int L = 0; L < N; ++L) {
		int length = 0;

		for(int R = L; R < N; ++R) {
			if(v[L] != v[R])
				break;
			length++;
		}

		maxLength = max(maxLength, length);
	}

	return maxLength;
}

// O(N)
int longest_subarray_same_value(vector<int>& v) {
	const int N = v.size();
	int L = 0, R = 0;
	int largest = 0;

	while(R < N) {
		if(v[L] != v[R]) 
			L = R;

		largest = max(largest, R - L + 1);
		++R;
	}

	return largest;
}

// int fn()

int main() {
	vector<int> v {4, 2, 2, 3, 3, 3};
	cout << longest_subarray_same_value(v) << '\n';
	cout << longest_subarray_same_value_brute_force(v) << '\n';

	return 0;
}