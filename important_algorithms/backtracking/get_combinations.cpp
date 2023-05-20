#include<bits/stdc++.h>
using namespace std;

/**
 * Given array [1, 2, 3] and k = 2;
 * return all possible combination of 2 elements 3C2=3;
 * e.g. {1, 2}, {2, 3}, {1, 3} (Order doesn't matter in this)
 */

void combination(string, string, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string in = "ABCD";
	string out = "";
	int selectCount = 2;
	int k = 0;
	combination(in, out, selectCount, k);

	return 0;
}

void combination(string in, string out, int selectCount, int k) {
	if(k == selectCount) {
		cout << out << ' ';
		return;
	}
	if(in.empty()) 
		return;


	string left = out; // exclude
	string right = out; // include
	right.push_back(in[0]);
	in.erase(in.begin()); // remove first element;

	combination(in, left, selectCount, k);
	combination(in, right, selectCount, k + 1);
}
