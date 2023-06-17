#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	static void solve(string ip, string op, vector<string>& v) {
		if(ip.size() == 0) {
			v.push_back(op);
			return;
		}
		
		if(isalpha(ip[0])) {
			string a = op;
			string b = op;			

			a.push_back(tolower(ip[0]));
			b.push_back(toupper(ip[0]));
						
			ip.erase(ip.begin());
			solve(ip, a, v);
			solve(ip, b, v);
			return;
		} 
		
		string a = op;
		a.push_back(ip[0]);
		ip.erase(ip.begin());
		solve(ip, a, v);
	}

	static vector<string> letterCasePermutation(string s) {
		string input = s;
		string output = "";
		vector<string> v;
		
		solve(input, output, v);
		return v;
	}
};

int main() {
	const string s = "Jaimin Chokhawala";
	vector<string> v = Solution::letterCasePermutation("a1b1");
	for(auto& el: v) 
		cout << el << ' ';


	return 0;
}

