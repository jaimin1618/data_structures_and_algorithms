#include<bits/stdc++.h>
using namespace std;

const string WHITESPACE = " \n\r\t";

string ltrim(const string& s) {
	int start = s.find_first_not_of(WHITESPACE);
	if(start == string::npos) 
		return string("");
	return s.substr(start);
}

string rtrim(const string& s) {
	int end = s.find_last_not_of(WHITESPACE);
	if(end == string::npos)
		return string("");
	return s.substr(0, end + 1);
}

string trim(const string& s) {
	string tmp = s;
	return ltrim(rtrim(tmp));
}

int main() {
	string t = "   |jaimin__chokhwala|  ";
	cout << trim(t) << '\n';
	


	return 0;
}