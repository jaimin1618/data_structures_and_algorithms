#include<bits/stdc++.h>
using namespace std;

bool is_valid(vector<int>& v, int k, int maxPages) {
	int students = 1;
	int sum = 0;
	int n = v.size();

	for(int i = 0; i < n; ++i) {
		sum += v[i];
		if(sum > maxPages) {
			++students;
			sum = v[i];
		}
		if(students > k) 
			return false;
	}

	return true; 
}

int allocateBooks(vector<int>& v, int k) {
	int n = v.size();
	int max_pages_read = *max_element(v.begin(), v.end());
	int read_all_books = accumulate(v.begin(), v.end(), 0);

	if(n < k)
		return -1; // not possible to distribute 
	/**
	 * Maximum number of book student can read
	 * 
	 * |0-----40--------100|
	 * 		   ^	^	 ^
	 * 		   L   mid   R
	 */

	int L = max_pages_read;
	int R = read_all_books;
	int result = -1;

	while(L <= R) {
		int mid = L + (R - L) / 2; // let's take mid as max pages a student can read

		if(is_valid(v, k, mid) == true) {
			result = mid; // this scheme is possible solution
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {10, 20, 30, 40};
	int k = 2;

	cout << allocateBooks(v, k) << '\n';



	return 0;
}