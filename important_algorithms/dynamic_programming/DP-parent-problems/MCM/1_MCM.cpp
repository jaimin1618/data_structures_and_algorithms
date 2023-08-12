#include<bits/stdc++.h>
using namespace std;

int MCM(int v[], int i, int j) {
	if(i >= j) 
		return 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int tmp = MCM(v, i, k) + MCM(v, k + 1, j) + (v[i - 1] * v[k] * v[j]);
		mini = min(mini, tmp);
	}

	return mini;
}

int dp[1000 + 1][1000 + 1];
int MCMMemoized(int v[], int i, int j) {
	if(dp[i][j] != -1) 
		return dp[i][j];
	
	if(i >= j)
		return dp[i][j] = 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int tmp = MCMMemoized(v, i, k) + MCMMemoized(v, k + 1, j) + (v[i - 1] * v[k] * v[j]);
		mini = min(tmp, mini);
	}

	return dp[i][j] = mini;
}

int main() {
	int v[] {40, 20, 30, 10, 30};
	int n = sizeof(v) / sizeof(int);
	int i = 1, j = n - 1;
	cout << MCM(v, i, j) << '\n';

	memset(dp, -1, sizeof(dp));
	cout << MCMMemoized(v, i, j) << '\n';

	return 0;
}

/***
Steps to solve MCM based problems "()" parenthesis based
1) find i, j value
2) find right base condition
3) find loop for k / Move k (k = i -> k = j)
***/