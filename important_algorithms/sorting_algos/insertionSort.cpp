#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& v);

void insertionSort(vector<int>& v) {
	const int n = v.size();

	int j, key;
	for(int i = 1; i < n; ++i) {
		key = v[i];
		j = i - 1;

		while(j >= 0 && key < v[j]) {
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = key;
	}
}

int main() {
	vector<int> t = {3, 1, 5, 2, 4};
	print(t);
	insertionSort(t);
	print(t);


	return 0;
}

void print(vector<int>& v) {
	for(auto& el: v) 
		cout << el << ' ';
	cout << '\n';
}