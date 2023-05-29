#include<bits/stdc++.h>
using namespace std;

vector<int> getNSL(vector<int>& v) {
	const int n = v.size();
	vector<int> res;
	stack<pair<int, int>> s;

	for(int i = 0; i < n; ++i) {
		if(s.empty()) 
			res.push_back(-1);

		else if(!s.empty() && s.top().first < v[i])
			res.push_back(s.top().second);

		else if(!s.empty() && s.top().first >= v[i]) {

			while(!s.empty() && s.top().first >= v[i])
				s.pop();

			if(s.empty())
				res.push_back(-1);
			else
				res.push_back(s.top().second);
		}

		s.push(make_pair(v[i], i));
	}

	return res;
}

vector<int> getNSR(vector<int>& v) {
	const int n = v.size();
	vector<int> res;
	stack<pair<int, int>> s;

	for(int i = n - 1; i >= 0; --i) {
		if(s.empty())
			res.push_back(n);

		else if(!s.empty() && s.top().first < v[i])
			res.push_back(s.top().second);

		else if(!s.empty() && s.top().first >= v[i]) {

			while(!s.empty() && s.top().first >= v[i])
				s.pop();


			if(s.empty())
				res.push_back(n);
			else
				res.push_back(s.top().second);
		}

		s.push(make_pair(v[i], i));
	}

	reverse(res.begin(), res.end());
	return res;
}

// this is working fine 👍
double maxAreaHistogram(vector<int>& v) {
	const int n = v.size();
	double maxArea = .0;

	vector<int> left = getNSL(v);
	vector<int> right = getNSR(v);
	vector<int> weight(n), areas(n);

	for(int i = 0; i < n; ++i) { 
		weight[i] = right[i] - left[i] - 1;
		areas[i] = v[i] * weight[i];

		if(areas[i] > maxArea)
			maxArea = areas[i];
	}

	return maxArea;
}

double maxAreaRectangleInBinaryMatrix(vector<vector<int>>& mat) {
	const int n = mat.size();
	const int m = mat[0].size();
	double maxArea = .0;
	vector<int> hist;

	// get maxAreaHist of first row
	hist.assign(mat[0].begin(), mat[0].end());
	maxArea = maxAreaHistogram(hist);

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(mat[i][j] == 0) 
				hist[j] = 0;
			else
				hist[j] += mat[i][j];
		}

		maxArea = max(maxArea, maxAreaHistogram(hist));
	}

	return maxArea;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> mat {
		{0, 1, 1, 0},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 0, 0}
	};	
	cout << "Max area covered by rectangle: " << maxAreaRectangleInBinaryMatrix(mat) << '\n';

	return 0;
}