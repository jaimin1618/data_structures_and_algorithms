#include<bits/stdc++.h>
using namespace std;

/*** Kth Symbol in Grammar
0 
0 1
0 1 1 0
0 1 1 0 1 0 0 1
***/

int solve(int, int);

int main() {
	const int N = 5;
	
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j <= (1 << (i - 1)); ++j) {
			cout << solve(i, j) << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

int solve(int n, int k) {
	if(n == 1 || k == 1)
		return 0;
	
	int mid = (1 << (n - 1)) / 2;
	if(k <= mid) 
		return solve(n - 1, k); 
		
	int r = solve(n - 1, k - mid);
	r ^= (1 << 0); // complement
	
	return r;
}
