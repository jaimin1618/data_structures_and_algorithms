#include<bits/stdc++.h>
using namespace std;

/*
Q: Find element in nearly sorted array

What is nearly sorted? 
ith element (of sorted array) can be at position i - 1, i or i + 1
e.g 
[1, 2, 3, 4, 5]
[1, 2, 4, 3, 5]
[2, 1, 3, 5, 4]
*/

int modifiedBinarySearch(vector<int>& v, int k) {
	int n = v.size();
	int L = 0, R = n - 1;

	while(L <= R) {
		int mid = L + (R - L) / 2;

		// search the element at i, i + 1, i - 1 places
		if(k == v[mid])
			return mid;
		if(mid - 1 >= L && k == v[mid - 1]) 
			return mid - 1;
		if(mid + 1 <= R && k == v[mid + 1])
			return mid + 1;

		if(k < v[mid])
			R = mid - 2;
		else
			L = mid + 2;
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> t1 {5, 10, 30, 20, 40};
	vector<int> t2 {10, 5, 30, 20, 40};

	for(auto& el: t1)
		cout << el  << " at: " << modifiedBinarySearch(t1, el) << '\n';

	for(auto& el: t2)
		cout << el  << " at: " << modifiedBinarySearch(t2, el) << '\n';







	return 0;
}