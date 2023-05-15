#include<bits/stdc++.h>
using namespace std;

vector<int> get_prefix_sum(vector<int>& v) {
	const int M = v.size();
	vector<int> result;
	int sum = 0;

	for(auto& el: v) {
		sum += el;
		result.push_back(sum);
	}

	return result;
}

vector<int> get_prefix_product(vector<int>& v) {
	const int M = v.size();
	vector<int> result;
	int prod = 1;

	for(auto& el: v) {
		prod *= el;
		result.push_back(prod);
	}

	return result;
}

int querySum(vector<int>& prefix_sum, int L, int R) {
	if(L <= 0)
		return prefix_sum[R];
	return prefix_sum[R] - prefix_sum[L - 1];
}

int main() {
	vector<int> v {2, -1, 3, -3, 4};
	vector<int> prefix_sum = get_prefix_sum(v);
	vector<int> prefix_product = get_prefix_product(v);

	for(auto& el: prefix_sum) 
		cout << el << ' ';
	cout << '\n';

	for(auto& el: prefix_product) 
		cout << el << ' ';
	cout << '\n';

	cout << querySum(prefix_sum, 0, 3) << '\n';
	cout << querySum(prefix_sum, 3, 4) << '\n';

	return 0;
}