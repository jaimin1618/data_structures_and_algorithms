#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

bool is_prime(int n) {
	for(int i = 2; i * i <= n; ++i) 
		if(n % i == 0)
			return false;

	return true;
}

vi factors(int n) {
	vi f;

	for(int i = 1; i < sqrt(n); ++i) {
		if(n % i == 0) {
			f.push_back(i);
			if(i != n / i) {
				f.push_back(n / i);
			}
		}
	}

	sort(f.begin(), f.end());
	return f;
}

// sieve's algo, find primes between 1 - N
vi sieve(int n) {
	int is_prime[n + 5] = {0};
	is_prime[0] = is_prime[1] = 1; // 0, 1 are primes

	for(int i = 2; i * i <= n; ++i) {
		if(!is_prime[i]) {
			for(int j = i * i; j <= n; j += i) {
				is_prime[j] = 1;
			}
		}
	}

	vi primes;

	for(int i = 0; i <= n; ++i) 
		if(!is_prime[i]) 
			primes.push_back(i);

	return primes;
}

void basic(int n) {
	int num[n + 1], sum[n + 1];
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));

	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			num[j]++;
			sum[j] += i;
		}
	}

	cout << "\nN: " << n << '\n';
	cout << "nums: ";
	for(int i = 0; i < n + 1; ++i) 
		cout << num[i] << " ";
	cout << "\nsums: ";
	for(int i = 0; i < n + 1; ++i) 
		cout << sum[i] << " ";
}

vi sortBasedOnNumberOfDivisors(vi input) {
	return vi();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vi f = factors(1000);
	for(const int& el: f) 
		cout << el << ' ';

	cout << "\nPrimes till: " << 100 << '\n';
	vi primes = sieve(100);
	for(const int& el: primes)
		cout << el << ' ';

	basic(25);

	

	return 0;
}