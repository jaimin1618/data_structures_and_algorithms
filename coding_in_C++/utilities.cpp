#include<bits/stdc++.h>
using namespace std;

struct Program {
	static int toInt(const char& c) {
		return isdigit(c) ? c - '0' : c - 'A' + 10; // considers 'A' = 10
	}
	
	template <typename T>
	static T convert_type(const string& input) {
		stringstream ss(input);
		T output;
		ss >> output; // consider ss ~ cin
		return output;
	}
	
	template <typename T>
	static int binarySearch(const vector<T>& v, int begin, int end, int key) {
		int L = begin;
		int R = end;
		
		while(L <= R) {
			int mid = L + (R - L) / 2;
			if(v[mid] == key) 
				return mid;
			else if(v[mid] < key)
				L = mid + 1;
			else 
				R = mid - 1;
		}
		
		return -1;
	};
	
	static const int MAXN = 1000;
	static const int MAXR = 1000;
	static long dp[MAXN][MAXR];
	static long nCr(int n, int r) {
		if(r == 1)
			return n;
		
			
		if(dp[n][r] != 0)
			return dp[n][r]; 
		return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
	}
};

int main() {
	cout << Program::toInt('1') + 100 << '\n';
	cout << Program::convert_type<int>("100") + 100 << '\n';	
	cout << Program::nCr(100, 10) << '\n';

	return 0;
}
