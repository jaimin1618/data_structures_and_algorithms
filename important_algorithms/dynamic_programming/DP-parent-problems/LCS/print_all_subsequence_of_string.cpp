#include<bits/stdc++.h>
using namespace std;

// Using INPUT/OUTPUT method for printing all subsequence of string
set<string> s;		
void printSubsequences(string input, string output) {
	if(input.empty()) {
		s.insert(output);
		return;
	}

	string op1 = output;
	string op2 = output;

	printSubsequences(input.substr(1), op1 + input[0]);
	printSubsequences(input.substr(1), op2);
} 

int main() {
	string in = "abc";
	int n = in.length();
	string out = "";
	printSubsequences(in, out);
	cout << '|';
	for(auto& el: s) 
		cout << el << '|';
	cout << '\n';


	return 0;
}