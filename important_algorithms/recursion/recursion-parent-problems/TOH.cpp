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
	int N = 2;
	char S, D, H;
	S = 'S';
	D = 'D';
	H = 'H';
	
	TOH(N, S, H, D);
		
	

	return 0;
}

void TOH(int n, char S, char H, char D) {
	if(n == 0)
		return;
	
	TOH(n - 1, S, H, D);
	cout << "Move disk: " << n << " from " << S << " to " << D << '\n';
	TOH(n - 1, H, D, S);
}
