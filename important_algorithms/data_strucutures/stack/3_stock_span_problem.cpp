#include<bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int>& v) {
	int n = v.size();
	vector<int> res(n);

	for(int i = 0; i < n; ++i) {
		int count = 0;

		// j = f(i), dependent on i (loop), we can optimize using Stack
		for(int j = 0; j <= i; ++j) {
			if(v[j] <= v[i])
				count++;
		}

		res[i] = count;
	}

	return res;
}

// stock Span problem == Nearest Greater to Left
vector<int> stockSpanOptimized(vector<int>& v) {
	// ip: [100, 80, 60, 70, 60, 75, 85] 
	// 1st: (get index of nearest greater to left) [-1, 0, 1, 1, 3, 1, 0]
	// then get the count of smaller elements including itself [1, 1, 1, 2, 1, 4, 7]
	const int n = v.size();
	vector<int> idxOfNearestGreater;
	stack<pair<int,int>> s;

	for(int i = 0; i < n; ++i) {
		if(s.empty())
			idxOfNearestGreater.push_back(-1);

		else if(!s.empty() && s.top().first >= v[i])
			idxOfNearestGreater.push_back(s.top().second);

		else if(!s.empty() && s.top().first < v[i]) {

			while(!s.empty() && s.top().first < v[i])
				s.pop();

			if(s.empty())
				idxOfNearestGreater.push_back(-1);
			else
				idxOfNearestGreater.push_back(s.top().second);
		}

		s.push(make_pair(v[i], i));
	}

	vector<int> res(n);

	for(int i = 0; i < n; ++i) {
		res[i] = i - idxOfNearestGreater[i];
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {100, 80, 60, 70, 60, 75, 85};
	for(auto& el: bruteForce(v))
		cout << el << ' ';
	cout << '\n';

	for(auto& el: stockSpanOptimized(v))
		cout << el << " ";
	cout << '\n';


	return 0;
}