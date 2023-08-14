#include<bits/stdc++.h>
using namespace std;

int egg_dropping(int e, int f) {
	if(f == 0 || f == 1)
		return f;
	if(e == 1)
		return f;

	int mn = INT_MAX;

	for(int k = 1; k <= f; ++k) {
		int egg_breaks_case = egg_dropping(e - 1, k - 1);
		int egg_doesnot_break_case = egg_dropping(e, f - k);
		int tmp = 1 + max(egg_breaks_case, egg_doesnot_break_case);
		mn = min(mn, tmp);
	}

	return mn;
}

int dp[1001][1001];
int egg_dropping_memoized(int e, int f) {
	if(f == 0 || f == 1)
		return f;
	if(e == 1)
		return f;
	if(dp[e][f] != -1)
		return dp[e][f];

	int mn = INT_MAX;
	for(int k = 1; k <= f; ++k) {
		int eggBreak, noEggBreak;

		if(dp[e - 1][k - 1] != -1) {
			eggBreak = dp[e - 1][k - 1];
		} else {
			eggBreak = egg_dropping_memoized(e - 1, k - 1);
			dp[e - 1][k - 1] = eggBreak;
		}

		if(dp[e][f - k] != -1) {
			noEggBreak = dp[e][f - k]; 
		} else {
			noEggBreak = egg_dropping_memoized(e, f - k);
			dp[e][f - k] = noEggBreak;
		}

		int tmp = 1 + max(eggBreak, noEggBreak);
		mn = min(mn, tmp);
	}

	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int eggs = 3, floors = 5;
	cout << "Min attempts to find critical floor: " << egg_dropping(eggs, floors) << '\n';

	memset(dp, -1, sizeof(dp));
	cout << "Min attempts to find critical floor: " << egg_dropping_memoized(eggs, floors) << '\n';


	
	return 0;
}