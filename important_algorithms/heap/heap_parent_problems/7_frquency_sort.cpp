#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

/**
 * This question is interesting, because. 
 * Here we need to understand how we can implement Heap here
 * 
 * solution is easy, 
 * 1st make element => frequency MAP
 * 1 => 3
 * 2 => 2
 * 3 => 1
 * 4 => 1
 * 
 * prioritize frequency, 
 * using pi = pair<int, int> => {frequency, element}
 * 
 * we want HIGH frequencies on top so that we can add them in beginning of array
 */

void frequencySort(vector<int>& v) {
	unordered_map<int, int> mp;
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
		auto [f, el] = p;	
			
		while(f > 0) {
			sol.push_back(el);
			--f;
		}

		maxH.pop();
	}

	v.assign(sol.begin(), sol.end());
}

// solution using compare function and sort
class Compare {
public:
	bool operator() (const pi& a, const pi& b) {
		/*
		We can ignore this
		if(a.first == b.first)
			return a.second > b.second; // for same frq, smaller value on top
		*/
		return a.first < b.first; // higher frq on top
	}
};

vector<int> frequencySortWithCompare(vector<int>& v) {
	unordered_map<int, int> mp;

	// first make element => frq MAP
	for(auto& el: v)
		mp[el]++;

	// make priority queue of frq => element, with priority = Compare function
	priority_queue<pi, vector<pi>, Compare> pq;

	for(auto& [v, f]: mp) {
		const pi& p = make_pair(f, v);
		pq.push(p);
	}

	vector<int> result;
	while(!pq.empty()) {
		pi p = pq.top();
		auto [f, v] = p;

		while(f) {
			result.push_back(v);
			--f;
		}

		pq.pop();
	}

	return result;
}

int main() {
	vector<int> v {1, 2, 1, 1, 2, 3, 4};
	frequencySort(v);
	for(auto& el: v) 
		cout << el << ' ';
	cout << '\n';

	vector<int> result = frequencySortWithCompare(v);
	for(auto& el: result)
		cout << el << ' ';
	cout << '\n';


	return 0;
}
