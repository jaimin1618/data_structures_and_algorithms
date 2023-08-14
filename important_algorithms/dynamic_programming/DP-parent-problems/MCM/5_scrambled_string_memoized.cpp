#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b) {
	if(a.compare(b) == 0)
		return true;
	if(a.length() <= 1)
		return false;
}

bool scrambled_string(string a, string b) {
	if(a.empty() && b.empty())
		return true;
	if(a.length() != b.length())
		return false;
	
	return solve(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}