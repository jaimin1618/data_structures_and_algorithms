#include<bits/stdc++.h>
using namespace std;

int *v = NULL;
const int N = 3;

void stackAllocation() {
	int p[N] = {500, 1000, 2000};
	v = p;
}

void heapAllocation() {
	v = new int[3]{500, 1000, 2000};
}

int main() {
	stackAllocation();
	cout << "(Stack/local allocation) Array Size: " << N << '\n';
	for(int i = 0; i < 3; ++i) 
		cout << v[i] << ' ';
	cout << '\n';

	heapAllocation();
	cout << "(Heap allocation) Array Size: " << N << '\n';
	for(int i = 0; i < 3; ++i) 
		cout << v[i] << ' ';




	return 0;
}