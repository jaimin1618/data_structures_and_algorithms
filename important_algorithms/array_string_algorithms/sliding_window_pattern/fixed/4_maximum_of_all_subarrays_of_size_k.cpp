#include<bits/stdc++.h>
using namespace std;

vector<int> maximumOfAllSubarray(vector<int>& v, int k) {
	const int n = v.size();
	list<int> ls;
	vector<int> op;
	int i = 0, j = 0;

	while(j < n) {
		// calculations
		while(!ls.empty() && ls.front() < v[j])
			ls.pop_front();
		ls.push_back(v[j]);


		if(j - i + 1 < k) {
			++j;

		} else if(j - i + 1 == k) {
			// get answer
			int mx = ls.front();
			op.push_back(mx);

			// slide the window ++i
			if(mx ==  v[i]) 
				ls.pop_front();

			++i;
			++j;
		}
	}

	return op;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> ip {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;

	for(auto& el: maximumOfAllSubarray(ip, k))
		cout << el << ' ';

	return 0;
}