#include<bits/stdc++.h>
using namespace std;

// ??? doubtful, it gives wrong answer

int countSubsetSum(int v[], int n, int T) {
	int dp[n + 1][T + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
			if(i == 0 || j == 0) continue;;

			if(v[i - 1] <= j)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][T];
}

int countNumberSubsetsWithDiff(int v[], int n, int diff) {
	int sum = 0;
	for(int i = 0; i < n; ++i) 
		sum += v[i];

	int s1 = (sum + diff) / 2;
	return countSubsetSum(v, n, s1);
}

int main() {
	int v[] {1, 1, 2, 3};
	int n = sizeof(v) / sizeof(int);
	int diff = 1;
	cout << countNumberSubsetsWithDiff(v, n, diff) << '\n';

	return 0;
}