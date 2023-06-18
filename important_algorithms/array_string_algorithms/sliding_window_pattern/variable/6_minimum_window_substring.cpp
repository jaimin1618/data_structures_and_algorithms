#include<bits/stdc++.h>
using namespace std;

/*======================================
Important question of Sliding window, 
it is difficult question of sliding window and, 
you would be able to approach sliding window hard question if you have solved this once.

Question,
ip,
s = "timetopractice";
t = "toc";
all the letters of t must be present in substring (window) of s and in same quantity or more quantiy (but not less)
find minimum window length of all those substrings 
======================================*/

int minimumWindowSubstring(string s, string t) {
	const int n = s.length();
	int i = 0, j = 0;
	int mn = numeric_limits<int>::max();

	unordered_map<char, int> mp;
	for(auto& el: t)
		mp[el]++;
	int count = mp.size();

	while(j < n) {
		if(mp.find(s[j]) != mp.end())
			mp[s[j]]--;

		if(mp[s[i]] == 0) 
			count--;

		if(count == 0) {
			if(mp.find(s[i]) == mp.end()) {
				++i;
			} else {
				while(mp[s[i]] <= 0) {
					mp[s[i]]++;
					if(mp[s[i]] > 0)
						count++;
					mn = min(mn, j - i + 1);
					++i;
				}

				++j;
			}
		} else {
			++j;
		}
	}

	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "timetopractice";
	string t = "toc";
	cout << minimumWindowSubstring(s, t) << '\n'; // 

	s = "TOTMTAPTAT";
	t = "TTA";
	cout << minimumWindowSubstring(s, t) << '\n';


	
	return 0;
}