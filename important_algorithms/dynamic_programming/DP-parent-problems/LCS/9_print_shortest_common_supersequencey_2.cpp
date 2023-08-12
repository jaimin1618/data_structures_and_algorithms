#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> get_lcs_table(string a, string b) {
	int m = a.length();
	int n = b.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

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

	return dp;
}

string print_scs(string a, string b) {
	vector<vector<int>> dp = get_lcs_table(a, b);
	int m = a.length();
	int n = b.length();
	int i = m, j = n;


	string s = "";

	while(i > 0 && j > 0) {
		if(a[i - 1] == b[j - 1]) {
			s.push_back(a[i - 1]);
			--i;
			--j;
		} else {
			if(dp[i - 1][j] > dp[i][j - 1]) {
				s.push_back(a[i - 1]);
				--i;
			} else {
				s.push_back(b[j - 1]);
				--j;
			}
		}
	}

	while(i > 0) {
		s.push_back(a[i - 1]);
		--i;
	}

	while(j > 0) {
		s.push_back(b[j - 1]);
		--j;
	}

	reverse(s.begin(), s.end());
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a = "abcdef", b = "abcgef";
	cout << print_scs(a, b) << '\n';
	
	return 0;
}