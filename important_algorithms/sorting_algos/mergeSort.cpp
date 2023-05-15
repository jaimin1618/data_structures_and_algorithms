#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& v);

void merge(vector<int>& v, int start, int end) {
	vector<int> t = *(new vector<int>(end - start + 1));

	int i, j, k, mid;
	mid = start + (end - start) / 2;
	i = start;
	j = mid + 1;
	k = 0;

	while(i <= mid && j <= end) {
		if(v[i] < v[j]) {
			t[k] = v[i];
			++i;
		} else {
			t[k] = v[j];
			++j;
		}
		++k;
	}

	while(i <= mid) {
		t[k] = v[i];
		++i;
		++k;
	}

	while(j <= end) {
		t[k] = v[j];
		++j;
		++k;
	}

	for(i = start; i <= end; ++i) 
		v[i] = t[i - start];
}

void mergeSort(vector<int>& v, int start, int end) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(v, start, mid); // sort left subarray
		mergeSort(v, mid + 1, end); // sort right subarray
		merge(v, start, end); // merge two sorted subarrays
	}
}


int main() {
	vector<int> v = {3, 1, 2, 5, 4};
	print(v);
	mergeSort(v, 0, (int) v.size() - 1);
	print(v);


	return 0;
}

void print(vector<int>& v) {
	for(auto& el: v) 
		cout << el << ' ';
	cout << '\n';
}