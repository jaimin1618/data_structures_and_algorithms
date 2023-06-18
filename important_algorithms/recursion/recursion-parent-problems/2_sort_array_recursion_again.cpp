#include<bits/stdc++.h>
using namespace std;

/*=====================================
template for Recursive solution, 
1st: Think Decision strategy (Choice diagram)
2nd: If No Decision strategy then think Smaller input strategy that is implemented with IBH method

IBH Solution template
void printNumbers(int input) {
	// BASE CONDITION
	if(input == 0)
		return;

	// HYPOTHESIS => that is design a function IP/OP, printNumber(N) prints N numbers, printNumber(N - 1) prints N - 1 numbers
	printNumbers(input - 1);

	// INDEXION => works with hypothesis to get desired output of function
	cout << input << ' ';
}
=====================================*/

// this is valid solution
void recursiveSort(vector<int>& v, int n) {
	// base
	if(n == 1)
		return;

	// hypothesis
	recursiveSort(v, n - 1);

	// indextion
	for(int i = 0; i < n - 1; ++i) {
		if(v[i] > v[n - 1]) {
			swap(v[i], v[n - 1]);
		}
	}
}

// complete recursion solution
void insert(vector<int>& v, int item) {
	const int n = v.size();
	if(n == 0 || v[n - 1] <= item) {
		v.push_back(item);
		return;
	}

	int last = v[n - 1];
	v.pop_back();
	insert(v, item);
	v.push_back(last);
}

void sort(vector<int>& v) {
	int n = v.size();
	if(n == 1)
		return;	

	int t = v[n - 1];
	v.pop_back();
	sort(v);
	insert(v, t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> ip {2, 3, 7, 6, 4, 5, 9};
	sort(ip);

	for(auto& el: ip)
		cout << el << ' ';


	
	return 0;
}