#include<bits/stdc++.h>
using namespace std;

void printNumbers(int n) {
	if(n == 1) {
		cout << 1 << ' ';
		return;
	}
	
	printNumbers(n - 1);
	cout << n << ' ';
}

void printReverseNumbers(int n) {
	if(n == 1) {
		cout << n << ' ';
		return;
	}
	
	cout << n << ' ';
	printReverseNumbers(n - 1);
}

int main() {
	printNumbers(5);
	cout << '\n';
	printReverseNumbers(5);

	return 0;
}


/***
Approach for solving Recursion problem:
	1) Recursive tree (I/O method)
	2) Base condition - indexation - hypothesis
	3) Choice diagram 

***/
