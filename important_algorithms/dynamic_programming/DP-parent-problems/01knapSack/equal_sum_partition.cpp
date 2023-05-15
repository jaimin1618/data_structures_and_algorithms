#include<bits/stdc++.h>
using namespace std;

/***
INPUT: Array
OUTPUT: T/F
DESC: divide array in 2 parts such that sum of elements is equal
{1, 5, 5, 11} => {1, 5, 5} == {11}
**/

bool isSubsetSum(int v[], int N, int T) {
	bool dp[N + 1][T + 1];
	
	for(int i = 0; i < N + 1; ++i) {
		for(int j = 0; j < T + 1; ++j) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
			if(i == 0 || j == 0) continue; // don't touch 0th ROW or COLUMN
			
			if(v[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	return dp[N][T];
}

bool isSubsetSumPartitionPossible(int v[], int n) {
	int sum = 0;
	for(int i = 0; i < n; ++i) 
		sum += v[i];
	
	if(sum % 2 != 0) 
		return false;
		
	return isSubsetSum(v, n, sum / 2);
}

int main() {
	int v[] = {1, 5, 11, 5};
	int n = sizeof(v) / sizeof(int);
	cout << "Result: " << isSubsetSumPartitionPossible(v, n) << '\n';
	

	return 0;
}
