#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;

vii get_lcs_table(string x, string y) {
	int n = x.length();
	int m = y.length();
	vii dp(n + 1, vi(m + 1));

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < m + 1; ++j) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(x[i - 1] == y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp;
}

string print_lcs(string x, string y, int n, int m) {
	vii T = get_lcs_table(x, y);
	int i = n;
	int j = m;
	string result = "";

	while(i > 0 && j > 0) {
		if(x[i - 1] == y[j - 1]) {
			result.push_back(x[i - 1]);
			--i;
			--j;
		} else {
			if(T[i][j - 1] > T[i - 1][j])
				--j;
			else 
				--i;
		}
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string a = "acbcf";
	string b = "abcdf";
	cout << "Print LCS: ";
	cout << print_lcs(a, b, a.length(), b.length()) << '\n';


	return 0;
}