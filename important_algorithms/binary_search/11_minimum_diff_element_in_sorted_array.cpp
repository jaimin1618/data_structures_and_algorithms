#include<bits/stdc++.h>
using namespace std;

class MinimumDifferenceElementInSortedArray {
public:
	int solution(vector<int>& v, int K) {
		/**
		 * Solution is simple, but tricky to realize 
		 * - if KEY is present in array => return K as |K - K| = 0 minimum
		 * - [MY SOLUTION]else find Lower and Upper bound of Key and return min(|K-LB|, |K-UB|)
		 * - [BETTER SOLUTION], At the end of BS loop, if we do not find our element then our L and R
		 *   pointer will be pointing to our LB and UB, L => UB and R => LB
		 */

		int n = v.size();
		int L = 0, R = n - 1;

		while(L <= R) {
			int mid = L + (R - L) / 2;

			if(K == v[mid])
				return K;
			else if(K < v[mid]) 
				R = mid - 1;
			else 
				L = mid + 1;
		}

		// only diff in code (from BS is below lines)
		if(abs(L - K) < abs(R - K))
			return v[L];
		
		return v[R];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {4, 6, 10};
	int K = 7;
	// result = 6 (as |6-7|=1 is minimum)

	MinimumDifferenceElementInSortedArray s;
	cout << s.solution(v, K) << '\n';

	

	return 0;
}