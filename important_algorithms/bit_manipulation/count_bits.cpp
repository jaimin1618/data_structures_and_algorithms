#include<bits/stdc++.h>
using namespace std;

int count1Bits(int input) {
	int cnt = 0;

	while(input > 0) {
		if(input & 1) cnt++;
		input >>= 1;
	}

	return cnt;
}

int main() {
	cout << count1Bits(4) << '\n'; // 100
	cout << count1Bits(256) << '\n'; // 1_____
	cout << count1Bits(255) << '\n'; // 11111111 

	// done
	return 0;
}