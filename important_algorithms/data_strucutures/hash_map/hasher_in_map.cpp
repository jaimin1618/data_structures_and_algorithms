#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, string> mp;

	// getting hash function for above Map;
	unordered_map<string, string>::hasher hash_fn = mp.hash_function();
	// hash_fn(input) input is type of KEY and returns unique value of type size_t;

	cout << hash_fn("Jaimin") << '\n';
	cout << hash_fn("Jane Doe") << '\n';

	return 0;
}