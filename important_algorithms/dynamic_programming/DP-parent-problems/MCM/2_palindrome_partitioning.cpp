#include<bits/stdc++.h>

bool isPalindrome(const std::string& s, int i, int j) {
	if(i >= j)
		return true;
	while(i < j) {
		if(s[i] != s[j])
			return false;
		++i;
		--j;
	}

	return true;
}

bool is_palindrome(const std::string& s, int i, int j) {
	int n = j - i + 1;
	for(int k = i; k <= n / 2; ++k) {
		if(s[k] != s[n - k - 1]) {
			return false;
		}
	}
	return true;
}

int min_palindrome_partitioning(std::string s, int i, int j) {
	if(i >= j || is_palindrome(s, i, j))  
		return 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int tmp = 1 + 
		min_palindrome_partitioning(s, i, k) + 
		min_palindrome_partitioning(s, k + 1, j);

		mini = std::min(mini, tmp);
	}

	return mini;
}

int dp[1000 + 1][1000 + 1];
int min_palindrome_partitioning_memoized(std::string s, int i, int j) {
	if(dp[i][j] != -1) 
		return dp[i][j];
	if(i >= j || is_palindrome(s, i, j)) 
		return dp[i][j] = 0;

	int mini = INT_MAX;
	for(int k = i; k < j; ++k) {
		int tmp = 1 + 
		min_palindrome_partitioning_memoized(s, i, k) + 
		min_palindrome_partitioning_memoized(s, k + 1, j);

		mini = std::min(mini, tmp);
	}

	return dp[i][j] = mini;
}

int main() {
	std::string tests[3] = {
		"jaimin",
		"nitin",
		"ABCBA"
	};

	for(std::string& s: tests) {
		memset(dp, -1, sizeof(dp));
		int i = 0;
		int j = s.length() - 1;
		int result = min_palindrome_partitioning(s, i, j);
		std::cout << result << '\n';
		result = min_palindrome_partitioning_memoized(s, i, j);
		std::cout << result << '\n' << '\n';
	}

	return 0;
}