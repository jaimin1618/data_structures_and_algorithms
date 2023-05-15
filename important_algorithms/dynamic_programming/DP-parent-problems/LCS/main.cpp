#include<bits/stdc++.h>
using namespace std;

class F {
public:	
	static bool is_prime(const int& n) {
		for(int i = 2; i * i <= n; ++i) 
			if(n % i == 0)
				return false;
		return true;
	}
	static void get_primes(const int& n) {
		for(int i = 1; i <= n; ++i) {
			if(is_prime(i)) {
				cout << i << ' ';
			} 
		}
	}
};

int main() {
	F::get_primes(1000);

	return 0;
}