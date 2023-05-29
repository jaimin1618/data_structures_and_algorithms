#include<bits/stdc++.h>
using namespace std;

void pv(const vector<int>& v) {
	for(auto& el: v)
		cout << el << ' ';
	cout << '\n';
}

vector<int> maxElementToLeft(const vector<int>& v) {
	const int n = v.size();
	vector<int> mx(n);

	for(int i = 0; i < n; ++i) {
		if(i == 0) 
			mx[i] = v[i];
		else
			mx[i] = max(mx[i - 1], v[i]);
	}

	return mx;
};

vector<int> maxElementToRight(const vector<int>& v) {
	const int n = v.size();
	vector<int> mx(n);

	for(int i = n - 1; i >= 0; --i) {
		if(i == n - 1) 
			mx[i] = v[i];
		else
			mx[i] = max(mx[i + 1], v[i]);
	}

	return mx;
};

double rainWaterTrapping(vector<int>& v) {
	const int n = v.size();
	double area = .0;

	vector<int> mxL = maxElementToLeft(v);
	vector<int> mxR = maxElementToRight(v);
	vector<int> water(n);

	// in fact, no need to store in water[i], just do area += min(mxL, mxR) - v[i]
	for(int i = 0; i < n; ++i) {
		water[i] = min(mxL[i], mxR[i]) - v[i];
		area += water[i];
	}

	return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {3, 0, 0, 2, 0, 4};
	cout << rainWaterTrapping(v) << '\n';

	v.assign({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
	cout << rainWaterTrapping(v) << '\n';

	return 0;
}