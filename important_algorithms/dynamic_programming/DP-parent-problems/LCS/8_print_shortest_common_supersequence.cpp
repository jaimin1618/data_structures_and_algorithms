#include<bits/stdc++.h>
using namespace std;

const string print_scs(const string& a, const string& b) {

	auto dp_table = [=](string a, string b) {
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
	};

	vector<vector<int>> dp = dp_table(a, b);

	auto get_scs = [=](const string& a, const string& b, vector<vector<int>> dp) {
		int m = a.length();
		int n = b.length();
		int i = m;
		int j = n;
		string scs = "";

		while(i > 0 && j > 0) {
			if(a[i - 1] == b[j - 1]) {
				scs.push_back(a[i - 1]);
				--i;
				--j;
			} else if(a[i - 1] != b[j - 1]) {
				if(dp[i][j - 1] > dp[i - 1][j]) {
					scs.push_back(b[j - 1]);
					--j;
				} else {
					scs.push_back(a[i - 1]);
					--i;
				}
			}
		}

		while(i > 0) {
			scs.push_back(a[i - 1]);
			--i;
		}
		while(j > 0) {
			scs.push_back(b[j - 1]);
			--j;
		}

		return scs;
	};

	string scs = get_scs(a, b, dp);
	reverse(scs.begin(), scs.end());
	return scs;
}

int main() {
	const string a = "acbcf";
	const string b = "abcdaf";
	cout << "SCS result: ";

	const string s = print_scs(a, b);
	cout << s << '\n';	

	return 0;
}