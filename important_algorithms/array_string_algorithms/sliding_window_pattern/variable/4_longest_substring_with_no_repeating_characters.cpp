#include<bits/stdc++.h>
using namespace std;

int longestSubstringNoRepeatingCharacters(string s) {
	const int n = s.length();
	int i = 0, j = 0;
	int longestSubstring = numeric_limits<int>::min();
	unordered_map<char, int> mp;

	while(j < n) {
		mp[s[i]]++;

		int unique = mp.size();
		int k = j - i + 1; // window size

		if(unique == k) {
			longestSubstring = max(longestSubstring, k);
			++j;

		} else if (unique > k) {
			++j;

		} else {
			while(unique < k) {
				mp[s[i]]--;
				if(mp[s[i]] == 0) 
					mp.erase(mp.find(s[i]));
				unique = mp.size();
				++i;	
				k = j - i + 1;
			}

			++j;
		}
	}

	return longestSubstring;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "pwwkew";
	s = "abccba";
	cout << longestSubstringNoRepeatingCharacters(s) << '\n';
	
	return 0;
}