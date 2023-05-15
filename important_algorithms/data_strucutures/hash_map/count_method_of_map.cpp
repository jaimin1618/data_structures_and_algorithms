#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int,int> mp;

	mp[1] = 10;
	mp[2] = 20;
	mp[1] = 30;

	cout << mp.count(1) << '\n';


	return 0;
}