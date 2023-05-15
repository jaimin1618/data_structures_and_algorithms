#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& v) {
	for(auto& el: v) 
		cout << el << ' ';
	cout << '\n';
}

void selectionSort(vector<int>& v) {
	const int n = (int) v.size();

	for(int i = 0; i < n; ++i) {
		int minIdx = i;

		for(int j = i + 1; j < n; ++j) {
			if(v[j] < v[minIdx]) {
				minIdx = j;
			}
		}

		if(i != minIdx) {
			swap(v[i], v[minIdx]);
		}
	}
}

int main() {
	vector<int> t {3, 1, 5, 2, 4};
	print(t); 
	selectionSort(t);
	print(t);



	return 0;
}
