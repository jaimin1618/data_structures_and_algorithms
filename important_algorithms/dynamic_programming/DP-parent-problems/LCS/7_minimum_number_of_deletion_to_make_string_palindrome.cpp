#include<bits/stdc++.h>
using namespace std;

int longest_palindromic_subsequence_length(string s) {
	string r = s;
	reverse(r.begin(), r.end());

	auto lcs_length = [&](const string& x, const string& y) {
		int m = x.length();
		int n = y.length();
		int dp[m + 1][n + 1];

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
	};

	int lcs = lcs_length(s, r);
	return lcs;
}

int minimum_operations_to_make_string_palindrom(string s) {
	return s.length() - longest_palindromic_subsequence_length(s);
}

int main() {
	string in = "agbcba";
	cout << "Minimum operations to make string palindrome: ";
	cout << minimum_operations_to_make_string_palindrom(in) << '\n';


	return 0;
}

/*** NOTE:
Minimum insertion/deletion to convert string a => palindrom a
= length of a - LPS_length(a)
where, LPS_length(a) = LCS(a, reverse(a))
***/