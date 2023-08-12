#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j) {
	// 1) BASE CONDITION
	if(i > j)
		return 0;

	// STORING RESULT
	int mx = INT_MIN;

	// 2) CALCULATING TEMPORARY ANSWER
	for(int k = i; k < j; ++k) {
		// k goes from i to that's for sure, but increment and other function varies depending upon question
		int tmp = solve(arr, i, k) + solve(arr, k + 1, j);
		mx = max(tmp, mx);
	}

	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}