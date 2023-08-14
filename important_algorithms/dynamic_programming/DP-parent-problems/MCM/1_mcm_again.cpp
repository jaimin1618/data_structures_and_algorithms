#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int>& v, int i, int j) {
	if(i >= j)
		return 0;

	int minCost = INT_MAX;
	for(int k = i; k <= j - 1; ++k) {
		int cost = mcm(v, i, k) + mcm(v, k + 1, j) + v[i - 1] * v[k] * v[j];
		minCost = min(cost, minCost);
	}

	return minCost;
}

int dp[1001][1001];
int mcm_memoized(vector<int>& v, int i, int j) {
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i >= j)
		return 0;

	int minCost = INT_MAX;

	for(int k = i; k <= j - 1; ++k) {
		int cost = mcm(v, i, k) + mcm(v, k + 1, j) + v[i - 1] * v[k] * v[j];
		minCost = min(minCost, cost);
	}

	return dp[i][j] = minCost;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {10, 30, 5, 60};
	int n = v.size();
	int i = 1, j = n - 1;
	// why i = 1?, Observe carefully Matrix dims are defined by v[i - 1] X v[i]
	// of course you can take i = 0, j = n - 2;
	cout << mcm(v, i, j) << '\n';

	v.assign({40, 20, 30, 10, 30});
	n = v.size();
	i = 1, j = n - 1;
	cout << mcm(v, i, j) << '\n';

	v.assign({10, 20, 5});
	n = v.size();
	i = 1, j = n - 1;
	cout << mcm(v, i, j) << '\n';

	// DP / Memoized
	memset(dp, -1, sizeof(dp));

	v.assign({10, 30, 5, 60});
	n = v.size();
	i = 1, j = n - 1;
	cout << mcm_memoized(v, i, j) << '\n';


	v.assign({40, 20, 30, 10, 30});
	n = v.size();
	i = 1, j = n - 1;
	cout << mcm_memoized(v, i, j) << '\n';

	v.assign({10, 20, 5});
	n = v.size();
	i = 1, j = n - 1;
	cout << mcm_memoized(v, i, j) << '\n';

	
	return 0;
}