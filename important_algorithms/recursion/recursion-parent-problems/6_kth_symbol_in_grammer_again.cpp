#include<bits/stdc++.h>
using namespace std;

/*=======================================
BASE condition (n, k) = (1, 1) => 0

n = 1, k = 1 
0

n = 2,
0 1 

n = 3
0 1 1 0

n = 4
0 1 1 0 1 0 0 1
=======================================*/

// Kth symbol in grammer
int solve(int n, int k) {
	if(n == 1 && k == 1)
		return 0;

	int mid = pow(2, n - 1) / 2;
	if(k <= mid) 
		return solve(n - 1, k);
	else
		return !solve(n - 1, k - mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// output nth row and kth column value 0/1
	int n = 4;
	
	// generating solutions for n = 4 (row), k = 2^N cols
	for(int i = 1; i <= n; ++i) {
		for(int k = 1; k <= pow(2, i - 1); ++k) {
			cout << solve(n, k) << ' ';			
		}
		cout << '\n';
	}
		
	return 0;
}