#include<bits/stdc++.h>
using namespace std;

void space_permutations(string, string);

// main
int main() {
	string in, out;
	in = "ABC";

	// pre-process
	out.push_back(in[0]);
	in.erase(in.begin() + 0);
	
	space_permutations(in, out);

	return 0;
}

void space_permutations(string in, string out) {
	if(in == "") {
		cout << out << ' ';
		return;
	}

	// append with spaces
	string left = out; // prev output
	left.push_back('_');
	left.push_back(in[0]);
	// append without spaces;
	string right = out; // prev output
	right.push_back(in[0]);
	
	// make input small
	in.erase(in.begin() + 0);
	
	// recurse...
	space_permutations(in, left);
	space_permutations(in, right);
}
