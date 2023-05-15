#include<bits/stdc++.h>
using namespace std;

template <typename U, template V>
struct HashMap {
	static const int SIZE = 100;
	V *v = new V[SIZE];

	template <typename string>
	int stringHash(const string& input, int modulus = SIZE) {
		const int K = 997;
		int val = 0;
		for(const char& c: input) {
			val = (val * K + c) % modulus;
		}
		return val;
	}
	
};

int main() {

	return 0;
}
