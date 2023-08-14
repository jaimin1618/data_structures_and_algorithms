#include<bits/stdc++.h>
using string = std::string;

// scrambled string solution
bool fn(string a, string b) {
	if(a.compare(b) == 0)
		return true;
	if(a.length() <= 1)
		return false;

	int n = a.length();
	bool flag = false;
	for(int i = 1; i < n; ++i) {
		bool C1 = 
		fn(a.substr(0, i), b.substr(n - i, i)) && 
		fn(a.substr(i, n - i), b.substr(0, n - i));

		bool C2 = 
		fn(a.substr(0, i), b.substr(0, i)) && 
		fn(a.substr(i, n - i), b.substr(i, n - i));

		if(C1 || C2) {
			flag = true;
			break;
		}	
	}

	return flag;
}

bool scrambledString(string a, string b) {
	if(a.empty() && b.empty()) 
		return true;
	if(a.length() != b.length())
		return false;

	return fn(a, b);
}

int main() {
	string a = "great";
	string b = "tearg";
	bool result = fn(a, b);
	std::cout << "Are scrambled string: " << std::boolalpha << result <<'\n';




	return 0;
}