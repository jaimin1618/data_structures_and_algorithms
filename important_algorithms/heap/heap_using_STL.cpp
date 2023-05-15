#include<bits/stdc++.h>
using namespace std;

using ppi = pair<int,pair<int,int>>;
typedef pair<int,pair<int,int>> ppi;

void print_queue(priority_queue<int> q) {
	cout << "Queue: ";
	for(q; !q.empty(); q.pop())
		cout << q.top() << ' ';
	cout << '\n';
}

int main() {
	vector<int> v = {3, 5, 1, 2, 4};
	
	// max heap;
	priority_queue<int> maxh(v.begin(), v.end());
	priority_queue<
		int, 
		vector<int>, 
		greater<int>
	> minh(v.begin(), v.end());
	
	// max Heap
	cout << "Top => ";
	while(!maxh.empty()) {
		cout << maxh.top() << ' ';
		maxh.pop();
	}
	cout << " <= Bottom\n";
	
	// min Heap
	cout << "Top => ";
	while(!minh.empty()) {
		cout << minh.top() << ' ';
		minh.pop();
	}
	cout << " <= Bottom\n";
	
	priority_queue<int> x;
	vector<int> t = {2, 3, 1};
	for(int& el: t) x.emplace(el);
	print_queue(x);

	return 0;
}
