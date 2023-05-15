#include<bits/stdc++.h>
using namespace std;

int lcs_length(string a, string b) {
	int m = a.length();
	int n = b.length();
	int dp[m + 1][n + 1];

	for(int i = 0; i < m + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(a[i - 1] == b[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

int shortest_common_supersequence_length(string a, string b, int n, int m) {
	return m + n - lcs_length(a, b);
}

int main() {
	string a = "geek";
	string b = "eke";
	// shortest common supersequence: geeke

	cout << "Shortest common super sequence length: ";
	cout << shortest_common_supersequence_length(a, b, a.length(), b.length());
	cout << '\n';	




	return 0;
}