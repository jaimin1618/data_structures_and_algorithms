#include<bits/stdc++.h>
using namespace std;

void iterateMap(unordered_map<string, int>& mp) {
	for(const auto& [k, v]: mp) 
		cout << k << ' ' << v << '\n';
}

int main() {
	unordered_map<string, int> mp;

	mp["JAIMN"] = 100;
	mp["JANE"] = 103;
	mp["JOHN"] = 302;

	iterateMap(mp);


	return 0;
}