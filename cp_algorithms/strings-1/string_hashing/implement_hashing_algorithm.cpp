#include<bits/stdc++.h>
using namespace std;
const long long MOD = (long long) 1e9 + 7;

long long get_hash(const string& s) {
	long long result = 0;
	const int P = 97;

	for(int i = 0; i < s.length(); ++i) {
		result += (long long) pow(P, i) * (long long) s[i] % MOD;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	

	vector<string> tests {
		"ABC",
		"abc",
		"jaimin",
		"C++"
	};

	cout << "String" << "\t" << "Hash" << '\n'; 
	for(auto& el: tests) {
		cout << el << "\t" << get_hash(el) << '\n'; 
	}

	return 0;
}