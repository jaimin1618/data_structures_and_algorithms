#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int v[], int N, int T) {
	int dp[N + 1][T + 1];
	
	for(int i = 0; i < N + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
			if(i == 0 || j == 0) continue;
			
			if(v[i - 1] <= j) 
				dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[N][T];
} 

int main() {
	int v[]{2, 3, 5, 6, 8, 10};
	int sum = 10;
	int n = sizeof(v) / sizeof(int);

	// tests
	for(int i = 0; i <= 35; ++i) {
		cout << "Target = " << i << '\t';
		cout << "Result: " << countSubsetSum(v, n, i) << '\n';
	}
	
	return 0;
}
