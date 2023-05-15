#include<bits/stdc++.h>
using namespace std;

// recursive
int knapSack(int wt[], int v[], int W, int n) {
	if(W == 0 || n == 0)
		return 0;

	if(wt[n - 1] <= W)
		return max(
			v[n - 1] + knapSack(wt, v, W - wt[n - 1], n - 1), 
			knapSack(wt, v, W, n - 1)
		);
	
	return knapSack(wt, v, W, n - 1);	
}

// memoization
const int MAXN = 100;
const int MAXW = 100;
int dp[MAXN + 1][MAXW + 1];

int knapSackMemo(int wt[], int v[], int W, int n) {
	if(n == 0 || W == 0) 
		return 0;
	
	if(dp[n][W] != -1)
		return dp[n][W];
		
	if(wt[n - 1] <= W) 
		return dp[n][W] = max(
			v[n - 1] + knapSackMemo(wt, v, W - wt[n - 1], n - 1), 
			knapSackMemo(wt, v, W, n - 1)
		);
		
	return dp[n][W] = knapSackMemo(wt, v, W, n - 1);
}

// iterative
int knapSackIter(int wt[], int v[], int W, int n) {
	int dp[n + 1][W + 1];	
	
	// iterate over all cells
	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < W + 1; ++j) {

			if(i == 0 || j == 0) {
				dp[i][j] = 0; // base condition

			} else if(wt[i - 1] <= j) {
				int include = v[i - 1] + dp[i - 1][j - wt[i - 1]];
				int exclude = dp[i - 1][j];
				dp[i][j] = max(include, exclude); // choice on current item

			} else if(wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j]; // cannot include current item
				
			}	
		}
	}
	
	return dp[n][W];
}


// main
int main() {
	int wt[]{10, 20, 30};
	int v[] = {60, 100, 120};
	int W = 50;
	int n = 3;

	cout << "Recursive: " << knapSack(wt, v, W, n) << '\n';
	memset(dp, -1, sizeof(dp));
	cout << "Memoized: " << knapSackMemo(wt, v, W, n) << '\n';
	cout << "Iterative: " << knapSackIter(wt, v, W, n) << '\n';


	return 0;
}

/*** Format to remember for coding DP solutions

Recursive:
int solution() {
	// BASE CONDITION

	// CHOICE DIAGRAM
}

Memoization
int solution() {
	// BASE CONDITION

	// if solved, return memo[i][j]

	// CHOICE DIAGRAM
}

Iterative
int solution() {
	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < w + 1; ++j) {
			// INITIALIZATION

			// CHOICE DIAGRAM
		}
	}
	return dp[n][w];
}
***/