#include<bits/stdc++.h>
using namespace std;

tuple<int,int> searchInSortedMatrix(vector<vector<int>>& mat, int k) {
	int n = mat.size();
	int m = mat[0].size();

	int i = 0, j = m - 1; // starting search from [0, COL - 1] or 1st ROW and last COL

	while(i >= 0 && i < n && j >= 0 && j < m) {
		if(k == mat[i][j]) 
			return make_tuple(i, j);

		else if(k < mat[i][j])
			--j;

		else
			++i;
	}

	return make_tuple(-1, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> v {
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 38},
		{32, 33, 39, 50}
	};
	int k = 29;
	auto [a, b] = searchInSortedMatrix(v, k);
	cout << "row: " << a << ", col: " << b << '\n';



	return 0;
}