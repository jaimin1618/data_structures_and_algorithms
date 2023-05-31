#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& v, int k) {
	const int n = v.size();
	int L = 0, R = 0;
	int mx = numeric_limits<int>::min();

	int sum = 0;
	while(R < n) {
		sum += v[R];

		if(R - L + 1 < k) {
			++R;
		} else if(R - L + 1 == k) {
			mx = max(mx, sum);
			sum -= v[L];
			++L;
			++R;
		}
	}

	return mx;
}

tuple<int,int,int> maxSumInSubarray(vector<int>& v, int k) {
	const int n = v.size();
	int mx = numeric_limits<int>::min();
	int low, high; // also get low and high for max sum

	int L = 0, R = 0, sum = 0;
	while(R < n) {
		if(R - L + 1 > k) {
			sum -= v[L];
			++L;
		}

		sum += v[R];			
		if(sum > mx) {
			mx = sum;
			low = L;
			high = R;			
		}
		++R;
	}
		
	return make_tuple(mx, low, high);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {2, 5, 1, 8, 2, 9, 1};
	int windowSize = 3; // ans = 1

	auto [s, low, high] = maxSumInSubarray(v, windowSize);
	cout << "max sum: " << s << '\n';
	cout << "Left index: " << low << ", Right index: " << high << '\n';

	cout << maxSum(v, windowSize) << '\n';


	return 0;
}