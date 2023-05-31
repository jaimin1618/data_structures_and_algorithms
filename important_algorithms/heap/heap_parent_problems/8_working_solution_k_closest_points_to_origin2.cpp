#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,pair<int,int>>;

vector<vector<int>> KClosestPoints(const vector<vector<int>>& points, int k) {
	priority_queue<pii> maxH;

	for(const vector<int>& point: points) {
		int x = point[0];
		int y = point[1];
		int dis = x * x + y * y;
		auto p = make_pair(dis, make_pair(x, y));
		maxH.push(p);
		if(maxH.size() > k) {
			maxH.pop();
		}
	}

	vector<vector<int>> sol;
	while(!maxH.empty()) {
		auto p = maxH.top();
		int x = p.second.first;
		int y = p.second.second;
		sol.push_back({x, y});
		maxH.pop();
	}

	return sol;
}

int main() {
	vector<vector<int>> points = {
		{1, 2},
		{-2, 2},
		{5, 8},
		{0, 1}
	};
	int k = 2;
	vector<vector<int>> result = KClosestPoints(points, k);
	for(auto& el: result) {
		cout << "(" << el[0] << "," << el[1] << ")" << '\n';
	}



	return 0;
}