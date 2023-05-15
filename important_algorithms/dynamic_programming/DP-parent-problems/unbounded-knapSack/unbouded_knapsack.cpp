#include<bits/stdc++.h>
using namespace std;

int unboundedKnapSack(int wt[], int v[], int W, int n) {
	int dp[n + 1][W + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < W + 1; ++j) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(wt[i] <= j) 
				dp[i][j] = max(
					v[i - 1] + dp[i][j - wt[i - 1]]
					dp[i - 1][j], 
				);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	return dp[n][W];
}

int main() {
	int wt[]{1, 2};
	int v[]{2, 1};
	int n = 2;
	int W = 3;
	cout << unboundedKnapSack(wt, v, W, n) << '\n';

	return 0;
}