#include<bits/stdc++.h>
using namespace std;
// NOTE: this is unbounded KnapSack

int dp[100 + 1][100 + 1];
int coin_change_Memo(int coin[], int n, int T) {
	if(T == 0) return dp[n][T] = 1;
	if(n == 0) return dp[n][T] = 0;
	if(dp[n][T] != -1) return dp[n][T];

	if(coin[n - 1] <= T) 
		return dp[n][T] = coin_change_Memo(coin, n, T - coin[n - 1]) 
		+ coin_change_Memo(coin, n - 1, T);

	return coin_change_Memo(coin, n - 1, T);
}


int coin_change(int coin[], int n, int T) {
	if(T == 0) return 1;
	if(n == 0) return 0;

	if(coin[n - 1] <= T)
		return coin_change(coin, n, T - coin[n - 1]) + 
		coin_change(coin, n - 1, T);

	return coin_change(coin, n - 1, T);
}

int coinChainMaximumWays(int coin[], int n, int T) {
	int& W = T;
	int dp[n + 1][W + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < W + 1; ++j) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
			if(i == 0 || j == 0) continue;

			if(coin[i - 1] <= j) 
				dp[i][j] = dp[i - 1][j] 
				+ dp[i][j - coin[i - 1]];
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];	
} 

int main() {
	int coin[] {1, 2, 3};
	int n = sizeof(coin) / sizeof(int);
	int sum = 5; // find ways to get 5 using coins[]
	memset(dp, -1, sizeof(dp));

	cout << "Maximum possible ways: " << coinChainMaximumWays(coin, n, sum) << '\n';
	cout << "Maximum possible ways: " << coin_change(coin, n, sum) << '\n';
	cout << "Maximum possible ways: " << coin_change_Memo(coin, n, sum) << '\n';


	return 0;
}