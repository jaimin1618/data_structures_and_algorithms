#include<bits/stdc++.h>
using namespace std;

// Many things are different in this problem than typical unbounded knapSack
template <typename T>
static void printv(const T v[], int n) {
	for(int i = 0; i < n; ++i) 
		cout << v[i] << ' ';
	cout << '\n';
}

int minimum_number_of_coins(int coin[], int n, int T) {
	int dp[n + 1][T + 1];

	// initialization
	for(int j = 0; j < T + 1; ++j) 
		dp[0][j] = INT_MAX - 1;
	for(int i = 1; i < n + 1; ++i) 
		dp[i][0] = 0;
	for(int j = 1; j < T + 1; ++j) {
		int i = 1;
		if(j % coin[i - 1] == 0) 
			dp[i][j] = j / coin[i - 1]; // arr[0] means dp[1][j]
		else
			dp[i][j] = INT_MAX - 1;
	}

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i <= 1 || j == 0) continue;

			if(coin[i - 1] <= j) 
				dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coin[i - 1]]);
			else 
			    dp[i][j] = dp[i - 1][j];
		}
	}

	cout << '\n';
	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(dp[i][j] == INT_MAX - 1) 
				cout << "∞";
			else 
				cout << dp[i][j];
			cout << ' ';
		}
		cout << '\n';
	}

	return dp[n][T];
}



int main() {
	int coin[] {2, 1};
	int n = 3;
	int T = 5; // ans: (2 + 3) = 5 => 2 coins minimum
	cout << "Minimum coin required: ";
	cout << minimum_number_of_coins(coin, n, T) << '\n';

	return 0;
}