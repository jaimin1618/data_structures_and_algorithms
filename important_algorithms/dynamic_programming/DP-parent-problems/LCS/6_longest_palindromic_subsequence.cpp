#include<bits/stdc++.h>
using namespace std;

int LCS_length_recursive(string a, string b, int m, int n) {
	if(n == 0 || m == 0)
		return 0;

	if(a[m - 1] == b[n - 1]) 
		return 1 + LCS_length_recursive(a, b, m - 1, n - 1);

	return max(
		LCS_length_recursive(a, b, m - 1, n), 
		LCS_length_recursive(a, b, m, n - 1)
	);
}

int LCS_length(string a, string b) {
	int m = a.length();
	int n = b.length();
	int dp[m + 1][n + 1];

	for(int i = 0; i < m + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(a[i -1] == b[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(
					dp[i - 1][j],
					dp[i][j - 1]
				);
		}
	}

	return dp[m][n];
}

int longest_palindromic_subsequence_length(string input) {
	string revs = input;
	reverse(revs.begin(), revs.end());
	return LCS_length(input, revs);
}

int main() {
	string input = "agbcba";
	cout << "Longest palindromic subsequence length: ";
	cout << longest_palindromic_subsequence_length(input) << '\n';

	return 0;
}

/***
NOTE for LPS:
for any given string A;
LPS(A) = LCS(A, reverse(A))
***/