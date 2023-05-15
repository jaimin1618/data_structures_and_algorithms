#include<bits/stdc++.h>
using namespace std;

// typical sliding window and brute force solution
int duplicatesInWindow(vector<int>& v, int k) {
	// fix the left point and move right point till window limit
	const int N = v.size();

	for(int L = 0; L < N; ++L) {
		for(int R = L + 1; R < min(N, L + k); ++R) {
			if(v[L] == v[R]) {
				return true;
			}
		}
	}

	return false;
}

// solution using Sliding window (L, R) and HashSet / unordered_set (optimized)
int closeDuplicates(vector<int>& v, int k) {
	const int N = v.size();
	unordered_set<int> window;
	int L = 0, R = 0;

	/**
	 * IMP Note:
	 * R used to grow the window size
	 * L used to slide the window to right 
	 */

	while(R < N) {
		// step and thought 3: Take action when windowSize is out of limit (k = 3)
		// R - L + 1 === window size
		int windowSize = R - L + 1;
		if(windowSize > k) {
			window.erase(v[L]); // remove first element
			L++; // slide the window to right
		}

		// step and thought 2: Solution (if 2 elements are same return)
		int is_found = window.count(v[R]);
		if(is_found > 0) return true;

		// step and thought 1: Fill the HashSet
		window.insert(v[R]);
		++R;
	}

	return false;
}

 

int main() {
	vector<int> v {1, 2, 3, 2, 3, 3};
	int window = 3;
	cout << duplicatesInWindow(v, window) << '\n';
	cout << closeDuplicates(v, window) << '\n';

	return 0;
}