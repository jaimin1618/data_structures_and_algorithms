#include<bits/stdc++.h>
using namespace std;

char nextLetter(vector<char>& v, char k) {
	int n = v.size();
	int L = 0, R = n - 1;
	char result = '\0';

	while(L <= R) {
		int mid = L + (R - L) / 2;

		if(k == v[mid])
			L = mid + 1; // we cannot return, as we need to find next letter
		else if(k > v[mid]) 
			L = mid + 1;
		else {
			result = v[mid];
			R = mid - 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<char> v {'a', 'b', 'f', 'h'};
	const char result = nextLetter(v, 'f');

	if(result != '#') {
		cout << result << '\n';
	} else {
		cout << "Not Found" << '\n';
	}


	return 0;
}