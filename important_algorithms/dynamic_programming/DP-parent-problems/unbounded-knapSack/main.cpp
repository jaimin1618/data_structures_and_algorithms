#include<bits/stdc++.h>
using namespace std;

// get minimum number of coins 
int coin_change(int coins[], int n, int sum) {
	int dp[n + 1][sum + 1];

	// init
	for(int j = 0; j < sum + 1; ++j)
		dp[0][j] = INT_MAX - 1;
	for(int i = 1; i < n + 1; ++i)
		dp[i][0] = 0;
	for(int j = 1; j < sum + 1; ++j) {
		int el = coins[0];
		if(j % el == 0)
			dp[1][j] = j / el;
		else
			dp[1][j] = INT_MAX - 1;
	}
	
	// choice diagram
	for(int i = 2; i < n + 1; ++i) {
		for(int j = 1; j < sum + 1; ++j) {
			if(coins[i - 1] <= j) {
				int include = 1 + dp[i][j - coins[i - 1]];
				int exclude = dp[i - 1][j];
				dp[i][j] = min(include, exclude);
			} else
				dp[i][j] = dp[i - 1][j];
		}
	}

	// result
	return dp[n][sum];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int coins[] {1, 2, 3};
	int sum = 5;
	int n = sizeof(coins) / sizeof(int);
	cout << coin_change(coins, n, sum) << '\n';

	
	return 0;
}