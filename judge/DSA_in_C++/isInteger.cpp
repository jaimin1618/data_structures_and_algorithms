#include<bits/stdc++.h>
using namespace std;

/**
 * Why use round() instead of floor();
 * 99.99 => 100 and check of intger 100
 * and 99.01 => 100 and check for integer 99
 */

const double EPS = 1e-12;

bool isInteger(const double& number) {
	double integer = round(number);
	double diff = fabs(number - integer);

	if(diff < EPS)
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << std::boolalpha;
	cout << isInteger(5.0) << '\n';
	cout << isInteger(5.1) << '\n';
	cout << isInteger(5.0000001) << '\n';
	cout << isInteger(99.999999999999) << '\n';
	cout << isInteger(99.000000000001) << '\n';

	return 0;
}