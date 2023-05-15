#include<bits/stdc++.h>
using namespace std;

// find if string a is subsequence of string b and return true/false
bool isSubSequencePatternMatch(string a, string b) {
	auto lcs_length = [=](const string& x, const string& y) {
		int m = a.length();
		int n = b.length();
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

	bool isASubsequenceOfB = false;
	if(a.length() == lcs_length(a, b)) {
		isASubsequenceOfB = true;
	}

	return isASubsequenceOfB;
}

int main() {
	string a = "AXY";
	string b = "ADXCPY";
	cout << boolalpha;
	cout << "Is " << a << " subsequence of " << b << ": "; 
	cout << isSubSequencePatternMatch(a, b) << '\n';



	return 0;
}