#include<bits/stdc++.h>
using namespace std;

void solve(int ones, int zeros, int n, string op) {
	if(n == 0) {
		cout << op << ' ';
		return;
	}

	string op1 = op;
	op1.push_back('1');
	solve(ones + 1, zeros, n - 1, op1);
 
	if(ones > zeros) {
		string op2 = op;
		op2.push_back('0');
		solve(ones, zeros + 1, n - 1, op2);
	}
}

void printBinaryNumber(int n) {
	int ones = 0, zeros = 0;
	string op = "";
	op.push_back('1');
	solve(ones + 1, zeros, n - 1, op);
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N = 2
	// 11 - SOL
	// 00
	// 10 - SOL
	// 01
	cout << "N = 2" << '\n';
	printBinaryNumber(2);
 
	// N = 3
	// 111 - S
	// 110
	// 101 - S
	// 011 
	// 001 
	// 100 
	// 010
	// 000
	cout << "N = 3" << '\n';
	printBinaryNumber(3);

	cout << "N = 4" << '\n';
	printBinaryNumber(4);

	
	return 0;
}