#include<bits/stdc++.h>
using namespace std;

/*=========================
Partition string in such a way that, all the partitioned string are Palindrome
and Minimize the number of Partitions (return the partition)

e.g. NITIN
2 partition => N | ITI | N
e.g. JAIMIN
3 partition => JAIMIN => J | A | IMI | N
=========================*/

bool is_palindrome(const string& s, int i, int j) {
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

int min_palindrome_partitioning(string s, int i, int j) {
	if(i >= j || is_palindrome(s, i, j))
		return 0;

	int mini = INT_MAX;

	for(int k = i; k < j; ++k) {
		int tmp = 1 + 
		min_palindrome_partitioning(s, i, k) + 
		min_palindrome_partitioning(s, k + 1, j);

		mini = min(mini, tmp); 
	}

	return mini;
}

int dp[1000 + 1][1000 + 1];
int min_palindrome_partitioning_memoized(string s, int i, int j) {
	if(dp[i][j] != -1) 
		return dp[i][j];
	if(i >= j || is_palindrome(s, i, j)) 
		return dp[i][j] = 0;

	int mini = INT_MAX;

	for(int k = i; k < j; ++k) {
		int tmp = 1 + 
		min_palindrome_partitioning_memoized(s, i, k) + 
		min_palindrome_partitioning_memoized(s, k + 1, j);

		mini = min(mini, tmp);
	}

	return dp[i][j] = mini;
}

int main() {
	vector<string> tests {
		"jaimin",
		"nitin",
		"ABCBA"
	};

	for(string& s: tests) {
		memset(dp, -1, sizeof(dp));
		int i = 0;
		int j = s.length() - 1;

		cout << s << '\n';
		cout << i << " " << j << '\n';
		
		int result = min_palindrome_partitioning(s, i, j);
		cout << result << '\n';
		result = min_palindrome_partitioning_memoized(s, i, j);
		cout << result << '\n' << '\n';
	}

	return 0;
}