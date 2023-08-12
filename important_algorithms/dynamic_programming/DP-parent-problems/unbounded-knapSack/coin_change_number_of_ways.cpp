#include<bits/stdc++.h>
using namespace std;

// max # of ways, infinite supply of coins
int coins_change_recursive(int coins[], int n, int sum) {
	if(sum == 0)
		return 1;
	if(n == 0) 
		return 0;


	if(coins[n - 1] <= sum) {
		int include = coins_change_recursive(coins, n, sum - coins[n - 1]);
		int exclude = coins_change_recursive(coins, n - 1, sum);
		return include + exclude;
	}

	return coins_change_recursive(coins, n - 1, sum);
}

int coins_change(int coins[], int n, int sum) {
	int dp[n + 1][sum + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < sum + 1; ++j) {
			if(j == 0)
				dp[i][j] = 1;
			else if(i == 0)
				dp[i][j] = 0;
			else if(coins[i - 1] <= j) {
				int include = dp[i][j - coins[i - 1]];
				int exclude = dp[i - 1][j];
				dp[i][j] = include + exclude;

			} else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][sum];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int coins[]{1, 2, 3};
	int n = sizeof(coins) / sizeof(int);
	int sum = 5;
	cout << coins_change(coins, n, sum) << '\n';

	
	return 0;
}