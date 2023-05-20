#include<bits/stdc++.h>
using namespace std;

/**
 * Given array [1, 2, 3]
 * return all possible subsets of that array 
 */

void subsets(vector<int>, vector<int>);
vector<vector<int>> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> in {1, 2, 3};
	vector<int> out;
	subsets(in, out);

	for(auto& alpha: result) {
		for(auto& beta: alpha) {
			cout << beta << ' ';
		}
		cout << '\n';
	}	

	return 0;
}

void subsets(vector<int> in, vector<int> out) {
	if(in.size() == 0) {
		result.push_back(out);
		return;
	}

	vector<int> left = out; // exclude;
	vector<int> right = out; // include;
	right.push_back(in[0]);

	auto it = in.begin();
	in.erase(it + 0); // making input smaller, after decision

	subsets(in, left);
	subsets(in, right);
}