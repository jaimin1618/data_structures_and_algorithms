#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> ip, int k, int idx, int& ans) {
	if(ip.size() == 1) {
		ans = ip[0];
		return;
	}

	int kill = (idx + k) % ip.size();
	ip.erase(ip.begin() + kill);
	solve(ip, k, kill, ans);
};

int josephusSolution(int n, int k) {
	vector<int> ip(n);
	iota(ip.begin(), ip.end(), 1); // puts 1 to ... till array size

	k--;
	int idx = 0;
	int ans = -1;
	solve(ip, k, idx, ans);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> v {
		{5, 2},
		{40, 7}
	};

	for(auto& el: v) {
		int n = el[0];
		int k = el[1];
		cout << josephusSolution(n, k) << '\n';
	}

	return 0;
}