#include<bits/stdc++.h>
using namespace std;

void swapSortGeneral(vector<int>& v) {
	const int n = v.size();
	int i = 0;

	// At max 2*N or N operations happen here, ~ O(N)
	while(i < n) {
		if(v[i] != v[v[i] - 1])
			swap(v[i], v[v[i] - 1]);
		else
			++i;
	}
}

void swapSortSimple(vector<int>& v) {
	const int n = v.size();

	for(int i = 0; i < n;  ++i)
		if(v[i] != v[v[i] - 1])
			swap(v[i], v[v[i] - 1]);
}

// explaing swap sorting for 1-to-N numbers - O(N)
void swapSort(vector<int>& v) {
	const int n = v.size();

	// e.g. sorting, [2, 1, 3]
	// right place for "2" is v[1] => v[2 - 1] => v[v[i] - 1]
	// right place for "1" is v[0] => v[1 - 1] => v[v[i] - 1]
	// ...
	for(int i = 0; i < n; ++i) {
		int current_position = i; // position or index
		int correct_position = v[current_position] - 1;

		if(v[current_position] != v[correct_position])
			swap(v[current_position], v[correct_position]);
	}
}

tuple<vector<int>, vector<int>> swapSortSolution(vector<int>& v) { 
	const int n = v.size();
	vector<int> duplicates, missings;

	swapSort(v); // apply swap sort on array

	// find duplicates / missing after swap sort
	for(int i = 0; i < n; ++i) {
		if(v[i] != i + 1) {
			missings.push_back(i + 1);
			duplicates.push_back(v[i]);
		}
	}

	return make_tuple(duplicates, missings);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// disclaimer: If given array is "const" / "read-only" array then you
	// cannot perform swap sort without new O(N) extra space
	// so, no point of doing this method if const vector<int>& v given

	// for that you will need to use bit manipulation or math or other solutions
	vector<int> v {2, 1, 2, 3, 4, 5, 4, 7};
	swapSort(v);
	for(auto& el: v)
		cout << el << ' ';
	cout << "\n";

	auto [duplicates, missings] = swapSortSolution(v);
	cout << "missing: ";
	for(auto& el: missings)
		cout << el << ' ';
	cout << '\n';
	cout << "duplicates: ";
	for(auto& el: duplicates)
		cout << el << ' ';
	cout << '\n';



	return 0;
}