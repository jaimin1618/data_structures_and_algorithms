#include<bits/stdc++.h>
using namespace std;

int countAnagramEasy(string s, string pat) {
	const int n = s.length();
	const int k = pat.length();
	int i = 0, j = 0;
	int anagramCount = 0;

	// get char -> char_count map of pat
	unordered_map<char, int> mp;
	for(auto& el: pat)
		mp[el]++;

	unordered_map<char, int> windowChars;
	while(j < n) {
		if(mp.find(s[j]) != mp.end())
			windowChars[s[j]]++;

		if(j - i + 1 < k) {
			++j;

		} else if(j - i + 1 == k) {
			bool isSameLength = windowChars.size() == mp.size();
			bool isAnagram = true;

			if(isSameLength) {
				for(auto& [ch, count]: windowChars) {
					if(mp[ch] != count) {
						isAnagram = false;
						break;
					}
				}
			}

			if(isAnagram)
				++anagramCount;

			if(windowChars.find(s[i]) != windowChars.end())
				windowChars[s[i]]--;

			++i;
			++j;
		}
	}

	return anagramCount;
}

int countAnagram(string s, string pat) {
	const int n = s.length();
	int k = pat.length();
	int i = 0, j = 0;
	int anagramCount = 0;

	// get map (char => count_of_char) from pat
	unordered_map<char, int> mp;
	for(auto& el: pat)
		mp[el]++;

	int count = mp.size();

	while(j < n) {
		// calculation
		if(mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;

			if(mp[s[j]] == 0) 
				count--;
		}

	
		if(j - i + 1 < k) {
			++j;

		} else if(j - i + 1 == k) {
			// count = 0 means we found the anagram
			if(count == 0) 
				++anagramCount;

			// sliding the window ++i, removing older effects
			if(mp.find(s[i]) != mp.end()) {
				mp[s[i]]++;
				if(mp[s[i]] == 1) 
					++count;
			}

			++i;
			++j;
		}

	}

	return anagramCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "forxxorfxdofr";
	string p = "for";
	cout << countAnagram(s, p) << '\n';

	s = "aabaabaa";
	p = "aaba";
	cout << countAnagram(s, p) << '\n';
	
	return 0;
}