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
};

int main() {
	cout << Program::toInt('1') + 100 << '\n';
	cout << Program::convert_type<int>("100") + 100 << '\n';

	return 0;
}
