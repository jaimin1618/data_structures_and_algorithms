#include<bits/stdc++.h>
using namespace std;

int connectRopesForMinimumCost(vector<int>& rope_lengths) {
	priority_queue<int,vector<int>,greater<int>> minH;
	int cost = 0;

	for(auto& el: rope_lengths) 
		minH.push(el);

	while(minH.size() > 1) {
		int first = minH.top();
		minH.pop();
		int second = minH.top();
		minH.pop();
		int result = first + second;
		cost += result;
		minH.push(result);
	} 

	return cost;
}

int main() {
	vector<int> rope_lengths {1, 2, 3, 4, 5};
	cout << "Min cost: " << connectRopesForMinimumCost(rope_lengths) << '\n';

	return 0;
}