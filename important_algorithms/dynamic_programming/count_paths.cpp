#include<bits/stdc++.h>
using namespace std;

// given n X n grid, count paths from top-left to bottom-right, 
// you can only move down or right

// 1st brute force method
int count_paths(int r, int c, int rows, int cols) {
	if(r == rows || c == cols) return 0; // out-of-bounds
	if(r == rows - 1 && c == cols - 1) return 1; // reached!

	return count_paths(r + 1, c, rows, cols) + count_paths(r, c + 1, rows, cols);
}

const int MAX = 100;
int dp[MAX + 1][MAX + 1];
int count_paths_MEM(int r, int c, int rows, int cols) {
	if(dp[r][c] != 0) return dp[r][c];
	if(r == rows || c == cols) return dp[r][c] = 0;
	if(r == rows - 1 && c == cols - 1) return dp[r][c] = 1;

	return dp[r][c] = count_paths_MEM(r + 1, c, rows, cols) + count_paths_MEM(r, c + 1, rows, cols);
}

int count_paths_ITER(int rows, int cols) {
	int dp[rows + 1][cols + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = rows - 1; i >= 0; --i) dp[i][cols - 1] = 1;
	for(int j = cols - 1; j >= 0; --j) dp[rows - 1][j] = 1;

	for(int i = rows - 1; i >= 0; --i) {
		for(int j = cols - 1; j >= 0; --j) {
			if(i == rows - 1 || j == cols - 1)
				continue;
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}	

	cout << "DP matrix: " << '\n';
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	return dp[0][0];
}

int main() {
	memset(dp, 0, sizeof(dp));
	cout << count_paths(0, 0, 4, 4) << '\n';
	cout << count_paths_MEM(0, 0, 4, 4) << '\n';
	cout << count_paths_ITER(4, 4) << '\n';


	return 0;
}