#include<bits/stdc++.h>
using namespace std;

int length_of_lcs(string x, string y) {
	int n, m;
	n = x.length();
	m = y.length();
	if(n == 0 || m == 0)
		return 0;

	if(x[n - 1] == y[m - 1])
		return 1 + length_of_lcs(x.substr(0, n - 1), y.substr(0, m - 1));

	// if(x[n - 1] != y[m - 1])
	return max(
		length_of_lcs(x.substr(0, n - 1), y), 
		length_of_lcs(x, y.substr(0, m - 1))
	);
}

// making things simpler
int LCS_length(string x, string y, int n, int m) {
	if(n == 0 || m == 0) return 0;

	if(x[n - 1] == y[m - 1])
		return 1 + LCS_length(x, y, n - 1, m - 1);

	return max(
		LCS_length(x, y, n - 1, m),
		LCS_length(x, y, n, m - 1)
	);
}

int memo[100 + 1][100 + 1];
int LCS_length_memoized(string x, string y, int n, int m) {
	if(n == 0 || m == 0) 
		return memo[n][m] = 0;

	if(memo[n][m] != -1)
		return memo[n][m];

	if(x[n - 1] == y[m - 1])
		return memo[n][m] = 1 + LCS_length_memoized(x, y, n - 1, m - 1);

	return memo[n][m] = max(
		LCS_length_memoized(x, y, n - 1, m),
		LCS_length_memoized(x, y, n, m - 1)
	);
}

int LCS_length_iterative(string x, string y) {
	int n = x.length();
	int m = y.length();
	int dp[n + 1][m + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < m + 1; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if(x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(
					dp[i - 1][j],
					dp[i][j - 1]
				);
			}
		}
	}

	return dp[n][m];
}

int main() {
	string x, y;
	x = "abcdgh";
	y = "abedfhr";
	cout << "Length of LCS: ";
	cout << length_of_lcs(x, y) << '\n';

	cout << "(simpler) Length of LCS: ";
	cout << LCS_length(x, y, x.length(), y.length()) << '\n';

	cout << "(iterative) Length of LCS: ";
	cout << LCS_length_iterative(x, y) << '\n';

	memset(memo, -1, sizeof(memo));
	cout << "(memoized) Length of LCS: ";
	cout << LCS_length_memoized(x, y, x.length(), y.length()) << '\n';

	return 0;
}

/*** 
NOTE: Always 3 things to think for Recursive / DP solution
1) Base Condition
2) Choice diagram (code will be cake walk)
3) Smaller input
***/