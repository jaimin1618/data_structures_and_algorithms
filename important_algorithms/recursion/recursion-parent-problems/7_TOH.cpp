#include<bits/stdc++.h>
using namespace std;

// ??? Not working properly
/***
1 => source
2 => destination
3 => helper
***/

void TOH(int, char, char, char);

int main() {
	int N = 3;
	char S, D, H;
	S = 'S';
	D = 'D';
	H = 'H';
	
	TOH(N, S, H, D);

	return 0;
}

void TOH(int n, char S, char H, char D) {
	if(n == 1) {
		cout << "Move disk: " << n << " from " << S << " to " << D << '\n';
		return;		
	}
	
	TOH(n - 1, S, D, H);
	cout << "Move disk: " << n << " from " << S << " to " << D << '\n';
	TOH(n - 1, H, S, D);
}
