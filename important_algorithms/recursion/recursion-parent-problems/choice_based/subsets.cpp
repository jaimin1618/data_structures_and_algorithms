#include<bits/stdc++.h>
using namespace std;

set<string> s;
void subsets(string, string);

// main
int main() {
	string in, out;
	in = "ABC";
	out = "";
	subsets(in, out);
	
	int i = 1;
	for(auto& el: s) {
		cout << i << ": ";
		cout << el << '\n';
		++i;
	}
		
	return 0;
}  

void subsets(string in, string out) {
	if(in.size() == 0) {
		s.insert(out);
		return;
	}	
	
	string left = out; // exclude
	string right = out;  // include
	right.push_back(in[0]);
	
	// making input smaller after decision
	string::iterator it = in.begin();
	in.erase(it + 0); // remove 0th element
	
	subsets(in, left);
	subsets(in, right);		
}
