#include<bits/stdc++.h>
using namespace std;

/**
 * [4, -1, 2, -7, 3, 4]
 * Q: Find NON-empty subarray with largest sum
 */

class Solution {
public:
	static int brute_force(vector<int>& v) {
		int largest_sum = numeric_limits<int>::min();
		int n = v.size();

		for(int i = 0; i < n; ++i) {
			int sum = 0;
			for(int j = i; j < n; ++j) {
				sum += v[j];
				if(sum > largest_sum) 
					largest_sum = sum;
			}	
		}

		return largest_sum;	
	}

	static int brute_force_faster(vector<int>& v) {
		int sum = 0;
		int largest_sum = numeric_limits<int>::min();

		for(const int& el: v) {
			sum = max(sum, 0);
			sum += el;
			largest_sum = max(largest_sum, sum);
		}

		return largest_sum;
	}
};

class Solution2 {
	// Find index of subarray (start and end), which gives maximum sum of inside element 
public:
	static tuple<int, int, int> sliding_window(vector<int>& v) {
		int n = v.size();
		int largest_sum = numeric_limits<int>::min();
		int sum = 0;
		int LIndex = 0, RIndex = 0;
		int L = 0, R = 0;

		/**
		 * IMP NOTE:
		 * R pointer is used to GROW the window
		 * L pointer is used to RESET the window starting
		 */

		while(R < n) {
			if(sum < 0) {
				// reset the left point of window
				sum = 0;
				L = R;
			}

			sum += v[R];

			if(sum > largest_sum) {
				largest_sum = sum;
				LIndex = L;
				RIndex = R;
			}

			++R;
		}

		return make_tuple(LIndex, RIndex, 1000);
	}
};


int main() {
	vector<int> v {4, -1, 2, -7, 3, 4};
	int result = Solution::brute_force(v);
	cout << "largest sum: " << result << '\n';

	result = Solution::brute_force_faster(v);
	cout << "largest sum: " << result << '\n';

	// tuple<int, int> result2 = Solution2::sliding_window(v);
	// auto [ a, b ] = result2;
	auto [a, b, ignore] = Solution2::sliding_window(v);
	// cout << "Left index: " << a << '\n' << "Right index: " << b << '\n';

	return 0;
}