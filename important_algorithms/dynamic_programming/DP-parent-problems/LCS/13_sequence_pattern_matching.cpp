#include<bits/stdc++.h>
using namespace std;

bool sequencePatternMatching(string pat, string text) {
	int m = pat.length();
	int n = text.length();
	int dp[m + 1][n + 1];

	for(int i = 0; i < m + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(pat[i - 1] == text[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n] == pat.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a = "AXY";
	string b = "ADXCPY";
	cout << sequencePatternMatching(a, b) << '\n';
	
	return 0;
}