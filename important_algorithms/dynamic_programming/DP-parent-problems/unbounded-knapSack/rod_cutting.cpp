#include<bits/stdc++.h>
using namespace std;

int rod_cutting(int len[], int price[], int n, int W) {
	int dp[n + 1][W + 1];	

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < W + 1; ++j) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(len[i - 1] <= j) 
				dp[i][j] = max(
					price[i - 1] + dp[i][j - len[i - 1]], 
					dp[i - 1][j]
				);
			else 
			    dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];
}

int rod_cutting(int price[], int n, int W) { // sometimes len (wt[]) array is NOT given
	int len[n];
	iota(len, len + n, 1); // {0, 1, 2, 3, ...}
	return rod_cutting(len, price, n, W);
}



int main() {
	int price[] {5, 6, 8, 8};
	int n = sizeof(price) / sizeof(int);
	int W = 4;
	cout << "Max profit possible: ";
	cout << rod_cutting(price, n, W) << '\n';

	return 0;
}