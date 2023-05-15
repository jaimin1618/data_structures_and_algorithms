#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	static void permutationChangeCase(string input, string output) {
		if(input == "") {
			cout << output << ' ';
			return;
		}
		
		string left, right;
		left = output;
		right = output;
		
		left.push_back(input[0] - 32);
		right.push_back(input[0]);
		
		input.erase(input.begin());
		permutationChangeCase(input, left);
		permutationChangeCase(input, right);		
	}
};

int main() {
	string in, out;
	in = "ab";
	out = "";
	Solution::permutationChangeCase(in, out);
	

	return 0;
}

