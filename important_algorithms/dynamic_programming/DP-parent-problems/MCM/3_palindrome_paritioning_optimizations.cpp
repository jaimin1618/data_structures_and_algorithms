#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(const string& s, int i, int j) {
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
int solve(const string& s, int i, int j) {
	if(dp[i][j] != -1) 
		return dp[i][j];
	if(i >= j || is_palindrome(s, i, j))
		return dp[i][j] = 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int left, right;	

		if(dp[i][k] != -1) {
			left = dp[i][k];  
		} else{
			left = solve(s, i, k);
			dp[i][k] = left;
		}

		if(dp[k + 1][j] != -1) {
			right = dp[k + 1][j];
		} else {
			right = solve(s, k + 1, j);
			dp[k + 1][j] = right;
		}

		int tmp = 1 + left + right;
		mini = min(tmp, mini);
	}

	return dp[i][j] = mini;
}

int main() {
	string s = "jaimin";
	memset(dp, -1, sizeof(dp));
	int result = solve(s, 0, s.length() - 1);
	cout << result << '\n';

	return 0;
}