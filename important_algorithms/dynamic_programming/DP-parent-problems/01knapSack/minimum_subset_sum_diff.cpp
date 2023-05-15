#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int v[], int N, int T) {
	bool dp[N + 1][T + 1];
	
	for(int i = 0; i < N + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
			if(i == 0 || j == 0) continue;
			
			if(v[i - 1] <= j) 
				dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	vector<int> r;
	for(int i = 0; i <= T / 2; ++i) 
		if(dp[N][i] == true) 
			r.push_back(i);

	return r;
}

int minimumSubsetSumDiff(int v[], int n) {
	int range = 0;
	for(int i = 0; i < n; ++i) 
		range += v[i];

	// so our subset sum partition range is: [0, range]
	vector<int> possibleSum = subsetSum(v, n, range);
	
	int mn = numeric_limits<int>::max();
	for(int& el: possibleSum) {
		mn = min(mn, range - 2 * el);
	}

	return mn;
}

int main() {
	int v[]{1, 6, 11, 5};
	int n = 4;
	cout << "Result: " << minimumSubsetSumDiff(v, n) << '\n';

	return 0;
}
