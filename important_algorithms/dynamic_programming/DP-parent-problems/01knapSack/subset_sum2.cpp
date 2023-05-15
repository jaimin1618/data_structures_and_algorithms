#include<bits/stdc++.h>
using namespace std;

bool subsetSumRecursive(int v[], int n, int W) {
	if(W == 0) return true;
	if(n == 0) return false;
	
	if(v[n - 1] <= W) 
		return subsetSumRecursive(v, n - 1, W - v[n - 1]) || subsetSumRecursive(v, n - 1, W);

	return subsetSumRecursive(v, n - 1, W);
}

bool subsetSum(int v[], int n, int W) {
	bool dp[n + 1][W + 1];

	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < W + 1; ++j) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
			if(i == 0 || j == 0) continue;

			if(v[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][W];
}

int main() {
	int v[] {2, 3, 7, 8, 10};
	int W = 11;
	int n = sizeof(v) / sizeof(int);
	for(int i = 0; i <= 30; ++i) {
		cout << "Sum = " << i << " =>  " << boolalpha << subsetSum(v, n, i) << "\tRecursive: " << subsetSumRecursive(v, n, i) << '\n';
	}


	return 0;
}