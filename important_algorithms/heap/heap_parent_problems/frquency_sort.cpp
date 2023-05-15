#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

void frequencySort(vector<int>& v) {
	unordered_map<int,int> mp;
	priority_queue<pi> maxH;

	for(auto& el: v) 
		mp[el]++;

	for(auto& el: mp) {
		const pi& p = make_pair(el.second, el.first);
		maxH.push(p);
	}

	vector<int> sol;
	while(!maxH.empty()) {
		const pi& p = maxH.top();
		int f = p.first;
		while(f > 0) {
			sol.push_back(p.second);
			--f;
		}
		maxH.pop();
	}

	v.assign(sol.begin(), sol.end());
}

int main() {
	vector<int> v {1, 2, 1, 1, 2, 3, 4};
	frequencySort(v);
	for(auto& el: v) 
		cout << el << ' ';


	return 0;
}
