#include<bits/stdc++.h>
using namespace std;

int longest_common_substring_length(string x, string y, int n, int m) {
	int dp[n + 1][m + 1];
	int mx = INT_MIN;

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < m + 1; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if(x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			    mx = max(mx, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}
	
	return mx;
}

int main() {
	string x = "abcde";
	string y = "abfce";
	cout << "Longest common substring: ";
	cout << longest_common_substring_length(x, y, x.size(), y.size()) << '\n';


	return 0;
}