#include<bits/stdc++.h>
using namespace std;

/***
INPUT: array, target sum
OUTPUT: true/false, 
DESC: is there subset exit in array with sum = target
***/

// memoization
const int MAXN = 1000;
const int MAXT = 1000;
int dp[MAXN + 1][MAXT + 1];

int isSubsetSumMemo(int wt[], int N, int T) {
	if(T == 0) return dp[N][T] = 1;
	if(N == 0) return dp[N][T] = 0;

	if(dp[N - 1][T] != -1) 
		return dp[N][T];
		
	if(wt[N - 1] <= T) {
		return dp[N][T] = max(
			isSubsetSumMemo(wt, N - 1, T - wt[N - 1]), 
			isSubsetSumMemo(wt, N - 1, T)
		);
	} 
	
	return dp[N][T] = isSubsetSumMemo(wt, N - 1, T);
}

// iterative
bool isSubsetSum(int v[], int N, int T) {
	bool dp[N + 1][T + 1];
	
	for(int i = 0; i < N + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) 
				dp[i][j] = false;
			if(j == 0)
				dp[i][j] = true;
			if(i == 0 || j == 0) continue;
			
			if(v[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
			} else if(v[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}	
	
	return dp[N][T];
}

int main() {
	int v[]{1, 5, 3, 7, 4};
	int sum = 12;
	int n = sizeof(v) / sizeof(int);
	cout << boolalpha;
	
	cout << "Iterative: " << isSubsetSum(v, n, sum) << '\n';
	
	memset(dp, -1, sizeof(dp));
	cout << "Memoization: " << isSubsetSumMemo(v, n, sum) << '\n';
	
	// t2
	int v2[] = {1, 5, 5, 11};
	sum = 11;
	cout << isSubsetSum(v2, 4, 11) << '\n';
	
	
	return 0;
}



/***
Notes:

1) for T/F boolean values max => ||, min => && to make sense. 

***/
