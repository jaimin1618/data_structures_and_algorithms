#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& v, int k) {
	// if no negative number in window, print 0
	const int n = v.size();
	int i = 0, j = 0;
	queue<int> negatives; // to store -ve numbers
	vector<int> res;

	while(j < n) {

		// similar to sum += v[j]
		if(v[j] < 0) 
			negatives.push(v[j]);

		// now, conditions
		if(j - i + 1 < k) {
			++j;

		} else if(j - i + 1 == k) {
			if(!negatives.empty()) 
				res.push_back(negatives.front());
			else
				res.push_back(0);

			if(!negatives.empty() && negatives.front() == v[i])
				negatives.pop(); 
			++j;
			++i;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {12, -1, -7, 8, -15, 30, 16, 28};
	// op: [-1, -1, -7, -15, -15, 0];
	int winSize = 3;
	vector<int> res = firstNegativeInWindow(v, winSize);

	for(auto& el: res) 
		cout << el << ' ';
	cout << '\n';
	

	return 0;
}