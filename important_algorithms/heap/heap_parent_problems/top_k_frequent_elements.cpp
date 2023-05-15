#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

// Min-Heap because finding numbers with Largest frequency
vector<int> KMostFrequentNumbers(vector<int>& v, int k) {
	vector<int> result;
	// key is frequency
	priority_queue<pi,vector<pi>,greater<pi>> minH;
	unordered_map<int,int> mp;

	// element => frequency mapping
	for(auto& el: v) 
		mp[el]++;

	for(auto& el: mp) {
		pi p = make_pair(el.second, el.first);
		minH.push(p);
		if(minH.size() > k) {
			minH.pop();
		}
	}

	while(!minH.empty()) {
		auto p = minH.top();
		result.push_back(p.second);
		minH.pop();
	}

	return result;
}

int main() {
	vector<int> v{1, 1, 1, 3, 2, 2, 4};
	int k = 2;
	for(auto& el: KMostFrequentNumbers(v, k))
		cout << el << ' ';
	cout << '\n';

	return 0;
}

/***
Here "KEY" for sorting heap internally can be anything
that's the main part of HEAP questions. 
You have to decide key. 

In finding K Closest to number, key was relative difference
between these numbers
Here, Frequency will be key to find K Most frequent
elements
***/