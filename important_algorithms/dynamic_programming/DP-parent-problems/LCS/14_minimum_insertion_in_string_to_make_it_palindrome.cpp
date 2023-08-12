#include<bits/stdc++.h>
using namespace std;

int minimumDeleteOperations(string input) {
	string rinput = input;
	reverse(rinput.begin(), rinput.end());

	int n = input.size();
	int dp[n + 1][n + 1];

	for(int i = 0; i < n + 1; ++i) {
		for(int j = 0; j < n + 1; ++j) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(input[i - 1] == rinput[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int LPS_length = dp[n][n];

	return n - LPS_length;
}

int minimumInsertionOperations(string input) {
	return minimumDeleteOperations(input);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input = "aebebda";
	cout << minimumInsertionOperations(input) << '\n';
	
	return 0;
}