#include<bits/stdc++.h>
using namespace std;

int longest_repeating_subsequence_length(const string& a) {
	string b = a;
	int n = a.length();

	int dp[n + 1][n + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(a[i - 1] == b[j - 1] && i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][n];
}

int main() {
	string input = "AABEBCDD";
	int result = longest_repeating_subsequence_length(input);
	cout << "Longest repeating subsequence: ";
	cout << result << '\n';

	return 0;
}