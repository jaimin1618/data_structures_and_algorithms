#include<bits/stdc++.h>
using namespace std;

bool is_palindrone(vector<int>& v) {
	const int N = v.size();
	int L = 0, R = N - 1;

	while(L < R) {
		if(v[L] != v[R]) 
			return false;
		++L;
		--R;
	}

	return true;
}

tuple<int,int> twoSum(vector<int>& v, int target) {
	const int N = v.size();
	int L = 0, R = N - 1;

	while(L < R) {
		int sum = v[L] + v[R];
		
		if(sum > target) --R;
		else if(sum < target) ++L;
		else return make_tuple(L, R);
	}

	return make_tuple(-1, -1);
}

int main() {
	vector<int> v {1, 2, 7, 2, 1};
	cout << is_palindrone(v) << '\n';
	v.clear();

	// sorted input array 
	v.assign({-1, 2, 3, 4, 7, 9});
	auto [a, b] = twoSum(v, 7);
	cout << a << " " << b << '\n';



	return 0;
}