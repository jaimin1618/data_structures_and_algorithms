#include<bits/stdc++.h>
using namespace std;

// TARGET SUM is exactly same problem as count number of subsets with given difference

int numberSubsetSum(int v[], int n, int T) {
	int dp[n + 1][T + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
			if(i == 0 || j == 0) continue;

			if(v[i - 1] <= j) 
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][T];
}

int targetSum(int v[], int n, int target) {
	int sum = 0;
	for(int i = 0; i < n; ++i) 
		sum += v[i];

	int s1 = ceil((double)(target + sum) / 2);
	return numberSubsetSum(v, n, s1);
}

int main() {
	int v[] {0,0,0,0,0,0,0,0,1};
	int target = 1;
	int n = sizeof(v) / sizeof(int);
	cout << targetSum(v, n, target) << '\n';


	return 0;
}