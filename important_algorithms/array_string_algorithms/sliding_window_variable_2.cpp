#include<bits/stdc++.h>
using namespace std;

// find minimum length subarray OR TargetSum
int minimumLengthSumSubarray(vector<int>& v, int target) {
	const int N = v.size();
	int L = 0, R = 0;
	int min_length = numeric_limits<int>::max();
	int sum = 0;

	while(R < N) {
		sum += v[R];

		// IMP: notice we have while(sum >= target) not if!
		while(sum >= target) {
			min_length = min(min_length, R - L + 1);
			sum -= v[L]; // remove previous window values 
			++L; // shrink window size
		}

		++R; // growing window size
	}

	return min_length == numeric_limits<int>::max() ? 0 : min_length;
}

int main() {
	vector<int> v {2, 3, 1, 2, 4, 3};
	int target = 6;
	cout << minimumLengthSumSubarray(v, target) << '\n';

	return 0;
}