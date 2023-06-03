#include<bits/stdc++.h>
using namespace std;

/**
 * This is 1 to N elements array related problem. 
 * We will use concept of SWAP SORT, to solve this problem 
 * we have to output missing and duplicate number in solution
 */

tuple<int, int> typicalSolution(vector<int>& v) {
	/**
	 * Issue here is O(N) space of map()
	 * our solution is still O(N) time complexity
	 * but we need O(1) space complexity  
	 */
	const int n = v.size();
	unordered_map<int, int> mp;
	int duplicate, missing;

	for(auto& el: v) 
		mp[el]++;

	// as we know elements are only 1 to N
	for(int i = 1; i <= n; ++i) {
		if(mp.find(i) == mp.end())
			missing = i;
		else if(mp[i] > 1)
			duplicate = i;
	}

	return make_tuple(duplicate, missing);
}

tuple<int, int> mathSolution(vector<int>& v) {
	const int n = v.size();
	int sumOfArray = 0, sumOfSquares = 0, sumN = n * (n + 1) / 2, sumSquaresN = n * (n + 1) * (2 * n + 1) / 6;

	for(auto& el: v) {
		sumOfArray += el;
		sumOfSquares += el * el;
	}

	// NOTE: this all comes from observation
	// eq1: a + b + c = sumN, eq2: a + b + b = sumOfArray
	// subtract both eq: c - b = sumOfArray - sumN
	// eq3: a^2 + b^2 + c^2 = sumSquaresN, eq4: a^2 + b^2 + b^2 = sumOfSquares
	// subtract both eq: c^2 - b^2 = sumOfSquares - sumSquaresN
	// now solve this two equations and you will get missing and duplicate
	// (c - b) (c + b) = sumOfSquares - sumSquaresN;

	int c_plus_b = (sumOfSquares - sumSquaresN) / (sumOfArray - sumN);
	int c_minus_b = sumOfArray - sumN;
	// c - b = sumOfArray - sumN
	// c + b = c_plus_b

	int b = (c_plus_b + c_minus_b) / 2;
	int e = b - c_minus_b;
	return make_tuple(b, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 4, 3, 4, 5}; // 2 missing, 4 duplicate
	auto [duplicate, missing] = typicalSolution(v);
	cout << duplicate << " " << missing << '\n';

	auto [a, b] = mathSolution(v);
	cout << a << " " << b << '\n';


	return 0;
}