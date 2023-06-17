#include<bits/stdc++.h>
using namespace std;
using vs = vector<string>;

/*================================
Generate all balanced parenthesis for given N

ip:
N = 2 (we can use 2 pairs of () brackets)

op:
(()), ()()
/*==============================*/

vector<string> res;
void generateBalancedParenthesis(int open, int close, string op) {
	if(open == 0 && close == 0) {
		res.push_back(op);
		return;
	}

	if(open > 0) {
		string op1 = op;
		op1.push_back('(');	
		generateBalancedParenthesis(open - 1, close, op1);
	}

	if(open < close) {
		string op2 = op;
		op2.push_back(')');
		generateBalancedParenthesis(open, close - 1, op2);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 3;
	int open = n, close = n;
	string op = "";
	generateBalancedParenthesis(open, close, op);

	for(auto& el: res)
		cout << el << ' ';
	cout << '\n';
	
	return 0;
}