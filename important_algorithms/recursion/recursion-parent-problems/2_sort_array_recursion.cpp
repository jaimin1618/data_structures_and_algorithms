#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;

void print(int v[], int n);
void recursiveSort(int v[], int n);

void insert(vector<int>& v, int item) {
	int n = (int) v.size();
	if(n == 0 || v[n - 1] < item) {
		v.push_back(item);
		return;
	}
	
	int t = v[n - 1];
	v.pop_back();	
	insert(v, item);
	v.push_back(t); 
}

	
void sort(vector<int>& v) {
	int n = (int) v.size();
	if(n == 0)
		return;
		
	int t = v[n - 1];
	v.pop_back();
	sort(v);
	insert(v, t);
}

int main() {
	int v[] = {5, 4, 3, 2, 1};
	int n = sizeof(v) / sizeof(int);
	recursiveSort(v, n - 1);
	print(v, n);

	vector<int> a(v, v + n);
	for(int& el: a) cout << el << ' ';
	cout << '\n';
	sort(a);
	for(int& el: a) cout << el << ' ';
		
	
	return 0;
}


// utilities
void print(int v[], int n) {
	for(unsigned int i = 0; i < n; ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

void recursiveSort(int v[], int n) {
	if(n == 0) 
		return;
	
	recursiveSort(v, n - 1);
	vector<int> t = vector<int>(n + 1);
	
	// using iteration
	int& curr = v[n];
	for(uint i = 0; i < n; ++i) {
		if(curr < v[i]) {
			swap(v[i], curr);
		}	
	}
} 

