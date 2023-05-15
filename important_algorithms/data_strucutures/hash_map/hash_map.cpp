#include<bits/stdc++.h>
using namespace std;

class HashMap {
public:
	static int capacity;

	HashMap() {
		storage = new int[capacity];
	}

	static const int get_hash(const string& s) {
		int sum = 0;
		for(const char& c: s) {
			sum += (int) c * 7 + 77;
		}
		return sum % capacity;
	}

	int& operator[](const string& k) {
		// overloading hm["k"] = Rvalue
		int hash = HashMap::get_hash(k);
		return storage[hash];
	}

	const int operator[](const string& k) const {
		// overloading hm["k"]
		int hash = HashMap::get_hash(k);
		return storage[hash];
	}

private:
	int *storage;
};

int HashMap::capacity = 100;

int main() {
	HashMap hm;

	hm["ahmedabad"] = 102;
	hm["surat"] = 200;
	hm["robot"] = 4020;
	cout << hm["ahmedabad"] << " " << hm["surat"] << " " << hm["robot"] << '\n';
	
	return 0;
}