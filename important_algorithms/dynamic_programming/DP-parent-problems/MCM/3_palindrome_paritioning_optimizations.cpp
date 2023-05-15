#include<bits/stdc++.h>

bool is_palindrome(const std::string& s, int i, int j) {
	if(i >= j)
		return true;
	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		++i;
		--j;
	}
	return true;
}

int dp[1000 + 1][1000 + 1];
int solve(const std::string& s, int i, int j) {
	if(dp[i][j] != -1) 
		return dp[i][j];
	if(i >= j || is_palindrome(s, i, j))
		return dp[i][j] = 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int s1 = dp[i][k] != -1 ? dp[i][k] : solve(s, i, k);
		int s2 = dp[k + 1][j] != -1 ? dp[k + 1][j] : solve(s, k + 1, j);
		int tmp = 1 + s1 + s2;

		mini = std::min(tmp, mini);
	}

	return dp[i][j] = mini;
}

int main() {
	std::string s = "jaimin";
	memset(dp, -1, sizeof(dp));
	int result = solve(s, 0, s.length() - 1);
	std::cout << result << '\n';

	return 0;
}