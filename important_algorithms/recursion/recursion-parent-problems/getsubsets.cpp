#include<bits/stdc++.h>
using namespace std;

int main() {
	string str = "abc";
	set<string> s = subsets(str);
	
	

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
