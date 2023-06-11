#include<bits/stdc++.h>
using namespace std;

/*============================
problem: find the longest substrings that has K unique characters
"aabacbebebe" => "aabacb", "cbebebe", "..."
============================*/

int longestSubstringKUniqueCharacters(string s, int k) {
	const int n = s.length();
	unordered_map<char, int> mp;
	int longestSubstring = numeric_limits<int>::min();
	int i = 0, j = 0;

	while(j < n) {
		mp[s[j]]++;
		int unique = mp.size();

		if(unique == k) {
			int substringLength = j - i + 1;
			longestSubstring = max(longestSubstring, substringLength);
			++j;

		} else if(unique < k) {
			++j; 

		} else if(unique > k) {			
			// remove ith element
			while(unique > k) {
				mp[s[i]]--;
				if(mp[s[i]] == 0)
					mp.erase(mp.find(s[i]));
				
				unique = mp.size();
				++i;
			}

			++j;
		}
	} 

	return longestSubstring;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "aabacbebebe";
	int k = 3;
	cout << longestSubstringKUniqueCharacters(s, k) << '\n';

	return 0;
}