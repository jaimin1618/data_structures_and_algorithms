#include<bits/stdc++.h>
using namespace std;

/**
 * return the size of longest sub-array, 
 * whose element sum = K
 */

int longestSumarrayOfSum(vector<int>& v, int target) {
	const int n = v.size();
	int i = 0, j = 0;
	int mxLen = numeric_limits<int>::min();
	int sum = 0;

	while(j < n) {
		sum += v[j];

		if(sum == target) {
			int windowSize = j - i + 1;
			mxLen = max(mxLen, windowSize);
			++j;
		} else if(sum < target) {
			++j;
		} else if(sum > target) {
			while(sum > target) {
				sum -= v[i];
				++i;
			}
			++j;
		}
	}

	return mxLen;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {4, 1, 1, 1, 2, 3, 5};
	int targetSum = 5;
	cout << longestSumarrayOfSum(v, targetSum) << '\n';

	v.assign({-5, 8, -14, 2, 4, 12});
	targetSum = -5;
	cout << longestSumarrayOfSum(v, targetSum) << '\n';

	
	return 0;
}