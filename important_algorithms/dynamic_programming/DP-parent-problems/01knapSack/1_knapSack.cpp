#include<bits/stdc++.h>
using namespace std;

/*===========================
KNAPSACK PROBLEM
===========================*/
int knapSack(int wt[], int v[], int W, int n) {
	// base condition: think of smallest valid input
	if(n == 0 || W == 0)
		return 0;

	// choice diagram
	if(wt[n - 1] <= W) {
		int included = v[n - 1] + knapSack(wt, v, W - wt[n - 1], n - 1);
		int excluded = knapSack(wt, v, W, n - 1);
		return max(included, excluded);
	}

	return knapSack(wt, v, W, n - 1);
}

int dp[1000][1000];
int knapSackMEMO(int wt[], int v[], int W, int n) {
	if(n == 0 || W == 0)
		return 0;
	if(dp[n][W] != -1)
		return dp[n][W];

	if(wt[n - 1] <= W) {
		return dp[n][W] = max(
			v[n - 1] + knapSackMEMO(wt, v, W - wt[n - 1], n - 1),
			knapSackMEMO(wt, v, W, n - 1)
		);
	}

	return dp[n][W] = knapSackMEMO(wt, v, W, n - 1);
}

int knapSackITER(int wt[], int v[], int W, int n) {
	int dp[n + 1][W + 1];

	// initialization ~ base condition
	for(int i = 0; i < n + 1; ++i)
		dp[i][0] = 0;
	for(int j = 0; j < W + 1; ++j)
		dp[0][j] = 0;

	// choice diagram
	for(int i = 1; i < n + 1; ++i) {
		for(int j = 1; j < W + 1; ++j) {
			// base condition already fulfilled in dp[][]

			if(wt[i - 1] <= j) {
				int included = v[i - 1] + dp[i - 1][j - wt[i - 1]];
				int excluded = dp[i - 1][j];
				dp[i][j] = max(included, excluded);

			} else {
				dp[i][j] = dp[i - 1][j];

			}		
		}
	}

	return dp[n][W];
}

/*===========================
SUBSET-SUM PROBLEM
===========================*/

/*===========================
EQUAL-SUM-PARTITION PROBLEM
===========================*/

/*===========================
COUNT-SUBSET-SUM PROBLEM
===========================*/

int main() {
	/*===========================
	KNAPSACK
	===========================*/
	int wt[] {1, 3, 4, 5};
	int v[] {1, 4, 5, 7};
	int W = 7;
	const int n = 4;
	cout << "Max profit: " << knapSack(wt, v, W, n) << '\n';
	memset(dp, -1, sizeof(dp));
	cout << "Max profit: " << knapSackMEMO(wt, v, W, n) << '\n';
	cout << "Max profit: " << knapSackITER(wt, v, W, n) << '\n';

	/*===========================
	SUBSET-SUM
	===========================*/

	/*===========================
	EQUAL-SUM-PARTITION
	===========================*/

	/*===========================
	COUNT-SUBSET-SUM
	===========================*/



	return 0;
}