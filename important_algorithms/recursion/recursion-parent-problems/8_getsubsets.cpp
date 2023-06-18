#include<bits/stdc++.h>
using namespace std;

vector<string> ss; // results
void get_subsets(string ip, string op) {
	if(ip.size() == 0) {
		ss.push_back(op);
		return;
	}

	string op1 = op; // include
	string op2 = op; // exclude
	op1.push_back(ip[0]);

	// make input smaller
	ip.erase(ip.begin());
	get_subsets(ip, op1);
	get_subsets(ip, op2);
}

int main() {
	string ip = "abc";
	string op = "";	
	get_subsets(ip, op);

	for(auto& el: ss) {
		if(el.size() == 0) 
			cout << "\'\'";
		else 
			cout << el;
		cout << ' ';
	}

	return 0;
}

/***
NOTES about "Recursion"

Identification: 
	+ Choices & Decision
	+ Different from DP because in DP identification is done with Choices and Optimality

Steps to solve:
	1) Make a decision tree (I/O method)
	2) Write the code... or what!, once recursive tree is done, we are DONE with problem
	
	
Importance of recursion: 
	+ Recursion is Fundamental concept of many problems and algorithmic techniques
	+ Recursion is parent of DP, Backtracking & D&C	
***/
