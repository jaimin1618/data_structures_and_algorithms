#include<bits/stdc++.h>

int main() {
	const int N = 5;
	const int M = 5;
	int dp[N][M];

	// Garbage values happend
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			std::cout << dp[i][j] << ' ';
		}
		std::cout << '\n';
	}

	// where does *dp + M * N points is similar to .end() after last element
	int v[3][3] {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
		// ______^_points here
	};

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			std::cout << v[i][j] << ' ';
		}
		std::cout << '\n';
	}

	auto beginv = *v;
	auto endv = *v + 3 * 3;
	auto last = *v + 3 * 3 - 1;
	std::cout << *beginv << '\n';
	std::cout << *endv << '\n';
	std::cout << *last << '\n';


	// fill using std::fill function
	auto start = *dp;
	auto end = *dp + M * N;

	std::fill(start, end, 7);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			std::cout << dp[i][j] << ' ';
		}
		std::cout << '\n';
	}

	// fill using std::fill_n elements for vector<vector<int>> mat;
	std::vector<std::vector<int>> mat(3, std::vector<int>(3));
	std::for_each(std::begin(mat), std::end(mat), 
		[=](auto& row) {
			std::fill(std::begin(row), std::end(row), 13);
		}
	);
	
	for(auto& r: mat) {
		for(auto& c: r) {
			std::cout << c << ' ';
		}
		std::cout << '\n';
	}

	int matrix[8][8];
	std::for_each(std::begin(matrix), std::end(matrix), 
		[=](auto& r) {
			std::fill(std::begin(r), std::end(r), 17);
		}
	);
	for(auto& r: matrix) {
		for(auto& c: r) {
			std::cout << c << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}