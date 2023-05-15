#include<bits/stdc++.h>
using namespace std;

// 1 if n is too big, -1 if too small, 0 is correct 
int isCorrect(int n) {
	if(n > 10) return 1;
	else if(n < 10) return -1;
	return 0;
}

int binaryRange(int low, int high) {
	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(isCorrect(mid) == 0) 
			return mid;
		else if(isCorrect(mid) > 0)
			high = mid - 1;
		else if(isCorrect(mid) < 0) 
			low = mid + 1;
	}

	return -1;
}

int main() {
	cout << binaryRange(0, 100) << '\n';
	cout << binaryRange(100, 1000) << '\n';


	return 0;
}