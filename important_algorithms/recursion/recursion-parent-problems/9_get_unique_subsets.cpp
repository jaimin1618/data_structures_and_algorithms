#include<bits/stdc++.h>
using namespace std;

set<string> ss;
void get_unique_subsets(string ip, string op = "") {
	if(ip.size() == 0) {
		ss.insert(op);
		return;
	}

	string op1 = op; // include
	string op2 = op; // exclude
	op1.push_back(ip[0]);
	ip.erase(ip.begin());

	get_unique_subsets(ip, op1);
	get_unique_subsets(ip, op2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string ip = "aab";
	get_unique_subsets(ip);

	for(auto& s: ss) {
		if(s == "")
			cout << "\'\'";
		else	
			cout << s;
		cout << ' ';
	}

	
	return 0;
}