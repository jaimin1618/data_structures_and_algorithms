#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ss;
void subsets(vector<int> ip, vector<int> op) {
	if(ip.empty()) {
		ss.push_back(op);
		return;
	}

	vector<int> op1 = op; // include
	vector<int> op2 = op; // exclude
	op1.push_back(ip[0]);
	ip.erase(ip.begin()); // smaller the input

	subsets(ip, op1);
	subsets(ip, op2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<int> ip {1, 2, 3};
	vector<int> op;
	subsets(ip, op);

	for(auto& r: ss) {
		for(auto& c: r) {
			cout << c << " ";
		}
		cout << '\n';
	}

	return 0;
}