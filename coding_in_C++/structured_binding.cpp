#include<bits/stdc++.h>
using namespace std;

int main() {
	// structural binding in C++
	pair<int,double> p {232, 45.46};
	auto [ i, d ] = p;
	cout << i << ' ' << d << '\n';

	// using get<i>(tuple OR pair OR any...)
	tuple<int,double,string> tu {10, 123.12, "Jaimin"};
	pair<string,int> sip {"Jaimin", 150};
	cout << get<0>(tu) << ' ' << get<1>(tu) << ' ' << get<2>(tu) << '\n';
	cout << get<0>(sip) << ' ' << get<1>(sip) << '\n';
	
	// structured binding with Static (know sized) arrays
	int v[] {10, 20, 30};
	auto [a, b, ignore] = v;
	cout << a << ' ' << b << '\n';
	
	vector<int> iv {10, 20, 30};
	// structured binding doesn't work with vectors because it has dynamic size at runtime. 
		

	


	return 0;
}
