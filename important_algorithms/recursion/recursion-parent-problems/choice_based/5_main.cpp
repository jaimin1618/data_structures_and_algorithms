#include<bits/stdc++.h>
using namespace std;

/*===============================
Permutation Spaces;

ip: 
ABC

op:
ABC
AB-C
A-BC
A-B-C
/*=============================*/

vector<string> result;
void permutationSpaces(string ip, string op) {
	if(ip == "") {
		result.push_back(op);
	} else if(op == "") {
		op.push_back(ip[0]);
		ip.erase(ip.begin());

		// no choice, include without spaces		
		permutationSpaces(ip, op);
	} else {
		string op1 = op; // with spaces
		string op2 = op; // without spaces

		// with spaces;
		op1.push_back('-');
		op1.push_back(ip[0]);

		// without spaces
		op2.push_back(ip[0]);

		// make input smaller
		ip.erase(ip.begin());

		permutationSpaces(ip, op1);
		permutationSpaces(ip, op2);
	}	
}

void permutationWithCase(string ip, string op) {
	if(ip == "") {
		result.push_back(op);
		return;
	}

	string op1 = op; // small
	string op2 = op; // capital
	op1.push_back(ip[0]);
	op2.push_back(ip[0] - 32);

	// make input smaller
	ip.erase(ip.begin() + 0);

	permutationWithCase(ip, op1);
	permutationWithCase(ip, op2);
}

void letterCasePermutation(string ip, string op) {
	if(ip == "") {
		result.push_back(op);
		return;
	}

	if(isdigit(ip[0])) {
		string op1 = op;
		op1.push_back(ip[0]);
		ip.erase(ip.begin() + 0);
		letterCasePermutation(ip, op1);

	} else {
		string op1 = op;
		string op2 = op;
		op1.push_back(tolower(ip[0]));
		op2.push_back(toupper(ip[0]));
		ip.erase(ip.begin() + 0);

		letterCasePermutation(ip, op1);
		letterCasePermutation(ip, op2);
	}
}

int main() {
	string ip = "ABC";
	string op = "";
	permutationSpaces(ip, op);

	cout << "permutations with spaces: ";
	for(auto& el: result) 
		cout << el << ' ';
	cout << '\n';
	result.clear();

	ip = "ab", op = "";
	permutationWithCase(ip, op);

	cout << "permutations with Case: ";
	for(auto& el: result)
		cout << el << ' ';
	cout << '\n';
	result.clear();

	ip = "a1B2", op = "";
	letterCasePermutation(ip, op);
	cout << "permutations with Case and numbers: ";
	for(auto& el: result)
		cout << el << ' ';
	cout << '\n';

	return 0;
}

