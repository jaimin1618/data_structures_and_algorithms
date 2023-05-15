#include<bits/stdc++.h>
using namespace std;

int get_lcs_length(string x, string y) {
	int m = x.length();
	int n = y.length();
	int dp[n + 1][m + 1];

	for(int i = 0; i < m + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(x[i - 1] == y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

int minimum_insertion_deleteion(string a, string b) {
	int M = a.size();
	int N = b.size();
	int LCS = get_lcs_length(a, b);

	int deletion = M - LCS;
	int insertion = N - LCS;

	return deletion + insertion;
}

int main() {
	string a = "heap";
	string b = "pea";
	cout << "Minimun insertion/Deletion operation required: ";
	cout << minimum_insertion_deleteion(a, b) << '\n';

	return 0;
}