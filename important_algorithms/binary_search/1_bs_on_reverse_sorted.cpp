#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& v, int item) {
	int n = v.size();
 	int mid, L = 0, R = n - 1;
 	// vector v is reverse sorted

 	while(L <= R) {
 		mid = L + (R - L) / 2;
 		if(item == v[mid])
 			return mid;
 		else if(item > v[mid]) 
 			R = mid - 1;
 		else if(item < v[mid])
 			L = mid + 1;
 	}

 	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {9, 6, 5, 3, 1, 0};
	cout << binarySearch(v, 5) << '\n';
	return 0;
}