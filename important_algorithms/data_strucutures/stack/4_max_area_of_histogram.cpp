#include<bits/stdc++.h>
using namespace std;

void pv(vector<int>& v) {
	for(auto& el: v)
		cout << el << ' ';
	cout << '\n';
}

/**
 * This problem can be broken down into below problems
 * - Nearest Smaller to Left, and Nearest Smaller to Right
 * - and then we can find area in between these NSL and NSR elements 
 */

vector<int> nearestSmallerLeftIndexes(vector<int>& v) {
// [6, 2, 5, 4, 5, 1, 6] => [-1, -1, 1, 1, 3, -1, 5]
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

vector<int> nearestSmallerRightIndexes(vector<int>& v) {
// [6, 2, 5, 4, 5, 1, 6] => [1, 5, 3, 5, 5, -1 , -1]
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

double maxAreaHistogram(vector<int>& v) {
	const int n = v.size();
	double maxArea = .0;

	vector<int> NSLIndexes = nearestSmallerLeftIndexes(v);
	vector<int> NSRIndexes = nearestSmallerRightIndexes(v);

	// pv(NSLIndexes);
	// pv(NSRIndexes);

	vector<int> width(n);
	for(int i = 0; i < n; ++i)
		width[i] = NSRIndexes[i] - NSLIndexes[i] - 1;
	// pv(width);

	vector<int> areas(n);
	for(int i = 0; i < n; ++i) {
		areas[i] = width[i] * v[i];
		if(areas[i] > maxArea)
			maxArea = areas[i];
	}
	// pv(areas);

	return maxArea;
}
/**
	Psuedo code for Max Area Histogram

	maxAreaHistogram(int arr[], int n) {
		left[] = NSL(arr, n);
		right[] = NSR(arr, n);
		weight[i] = left[i] - right[i] - 1; // width of building blocks
		areas[i] = arr[i] * width[i];
	}
 */


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {6, 2, 5, 4, 5, 1, 6};
	cout << "Max Histogram Area: " << maxAreaHistogram(v) << '\n';

	v.assign({2, 3, 3, 2});
	cout << "Max Histogram Area: " << maxAreaHistogram(v) << '\n';

 	  
 	//   | |
	// | | | |
	// | | | |


	

	return 0;
}

