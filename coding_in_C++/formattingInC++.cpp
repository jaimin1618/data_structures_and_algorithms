#include<bits/stdc++.h>
using namespace std;

int main() {
	// leading zeros
	cout << "=> Using Printf: " << '\n';
	int x = 123;
	printf("%05d\n", x);
	printf("%5d\n", x);
	
	// best method
	cout << "=> Using setw() and setfill(), setiosflags(align)" << '\n';
	cout << setw(5); 
	cout << setfill('0');
	cout << x << '\b';

	// C++20	
	cout << std::format("{:05d}", x);	
	
	return 0;
}

