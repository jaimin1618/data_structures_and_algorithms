#include<bits/stdc++.h>
using namespace std;


// if O == 0 && C == 0 => Output found
// if C > O then we can have choice of closing bracket in choice diagram
const char OPENED_PARENTHESIS = '(';
const char CLOSED_PARENTHESIS = ')';

void solve(int O, int C, string op, vector<string>& v) {
	// --- BASE CONDITION ---
	if(O == 0 && C == 0) {
		v.push_back(op);
		return;
	}
	
	// --- CHOICE DIAGRAM ---
	// always open choice;
	if(O != 0) {
		string op1 = op;
		op1.push_back(OPENED_PARENTHESIS);
		solve(O - 1, C, op1, v);
	}	
	
	// choice open only when Closed parenthesis are more than opened parenthesis;
	if(C > O) {
		string op2 = op;
		op2.push_back(CLOSED_PARENTHESIS);
		solve(O, C - 1, op2, v);
	}
}

vector<string> findAllBalancedParenthesis(int n) {
	vector<string> v;
	
	// pre-process
	int open, close;
	open = close = n;
	string op = "";
	
	op.push_back('(');
	solve(open - 1, close, op, v);	

	return v;
}

int main() {
	int n = 3; // 3 open 3 close parenthesis possible
	vector<string> result = findAllBalancedParenthesis(n);
	for(string& s: result) 
		cout << s << '\n';
		
	return 0;
}
